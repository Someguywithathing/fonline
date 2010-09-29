#include "StdAfx.h"
#include "ThreadSync.h"
#include <Windows.h>
#include "Mutex.h"

static MutexSpinlock SyncLocker; // Defense code from simultaneously execution

SyncObject::SyncObject():
curMngr(NULL)
{
}

void SyncObject::Lock()
{
	SyncLocker.Lock();

	SyncManager* curm=SyncManager::GetForCurThread();

	// Object is free
	if(!curMngr)
	{
		curMngr=curm;
		curMngr->lockedObjects.push_back(this);
	}
	// Object busy by another thread
	else if(curm!=curMngr)
	{
		// Another thread in wait state
		if(curMngr->isWaiting && curm->threadPriority>=curMngr->threadPriority)
		{
			// Pick from waiting thread
			SyncObjectVecIt it=std::find(curMngr->lockedObjects.begin(),curMngr->lockedObjects.end(),this);
			curMngr->lockedObjects.erase(it);
			curMngr->busyObjects.push_back(this);

			curMngr=curm;
			curMngr->lockedObjects.push_back(this);
		}
		// Another thread work with object
		else
		{
			// Go to wait state
			curm->isWaiting=true;
			curm->busyObjects.push_back(this);

			SyncLocker.Unlock();

			// Wait and try lock all busy objects
			while(true)
			{
				Sleep(0);

				SyncLocker.Lock();

				for(SyncObjectVecIt it=curm->busyObjects.begin();it!=curm->busyObjects.end();)
				{
					SyncObject* obj=*it;
					if(!obj->curMngr)
					{
						// Object free
						obj->curMngr=curm;
						curm->lockedObjects.push_back(obj);
						it=curm->busyObjects.erase(it);
					}
					else if(obj->curMngr->isWaiting && curm->threadPriority>=obj->curMngr->threadPriority)
					{
						// Pick from waiting thread
						SyncObjectVecIt it_=std::find(obj->curMngr->lockedObjects.begin(),obj->curMngr->lockedObjects.end(),obj);
						obj->curMngr->lockedObjects.erase(it_);
						obj->curMngr->busyObjects.push_back(obj);

						obj->curMngr=curm;
						curm->lockedObjects.push_back(obj);
						it=curm->busyObjects.erase(it);
					}
					else
					{
						// Object busy
						++it;
					}
				}

				if(curm->busyObjects.empty())
				{
					curm->isWaiting=false;

					SyncLocker.Unlock();
					return;
				}

				SyncLocker.Unlock();
			}
		}
	}
	// else object already locked by current thread

	SyncLocker.Unlock();
}

void SyncObject::Unlock()
{
	SCOPE_SPINLOCK(SyncLocker);

	if(curMngr)
	{
		SyncObjectVecIt it=std::find(curMngr->lockedObjects.begin(),curMngr->lockedObjects.end(),this);
		curMngr->lockedObjects.erase(it);
		curMngr=NULL;
	}

	for(SyncManagerVecIt it=SyncManager::Managers.begin(),end=SyncManager::Managers.end();it!=end;++it)
	{
		SyncManager* sync_mngr=*it;
		SyncObjectVecIt it_=std::find(sync_mngr->busyObjects.begin(),sync_mngr->busyObjects.end(),this);
		if(it_!=sync_mngr->busyObjects.end()) sync_mngr->busyObjects.erase(it_);
	}
}

SyncManagerVec SyncManager::Managers;

SyncManager::SyncManager():
isWaiting(false),
threadPriority(3) // Default priority
{
	lockedObjects.reserve(100);
	busyObjects.reserve(100);
	priorityStack.reserve(10);
}

SyncManager::~SyncManager()
{
	UnlockAll();
}

void SyncManager::PushPriority(int priority)
{
	SCOPE_SPINLOCK(SyncLocker);

	int prev_priority=threadPriority;
	priorityStack.push_back(prev_priority);
	threadPriority=priority;
}

void SyncManager::PopPriority()
{
	SCOPE_SPINLOCK(SyncLocker);

	threadPriority=priorityStack.back();
	priorityStack.pop_back();
}

void SyncManager::UnlockAll()
{
	SCOPE_SPINLOCK(SyncLocker);

	for(SyncObjectVecIt it=lockedObjects.begin(),end=lockedObjects.end();it!=end;++it)
	{
		SyncObject* obj=*it;
		obj->curMngr=NULL;
	}
	lockedObjects.clear();
}

void SyncManager::Suspend()
{
	SCOPE_SPINLOCK(SyncLocker);

	isWaiting=true;
}

void SyncManager::Resume()
{
	SyncLocker.Lock();

	isWaiting=false;

	if(!busyObjects.empty())
	{
		SyncObjectVec busy_objs=busyObjects;
		busyObjects.clear();

		SyncLocker.Unlock();

		for(SyncObjectVecIt it=busy_objs.begin(),end=busy_objs.end();it!=end;++it)
		{
			SyncObject* obj=*it;
			obj->Lock();
		}
	}
	else
	{
		SyncLocker.Unlock();
	}
}

SyncManager* SyncManager::GetForCurThread()
{
	static THREAD SyncManager* sync_mngr=NULL;
	if(!sync_mngr)
	{
		sync_mngr=new(nothrow) SyncManager();
		if(!sync_mngr) return NULL;
		Managers.push_back(sync_mngr);
	}
	return sync_mngr;
}




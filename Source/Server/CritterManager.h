//      __________        ___               ______            _
//     / ____/ __ \____  / (_)___  ___     / ____/___  ____ _(_)___  ___
//    / /_  / / / / __ \/ / / __ \/ _ \   / __/ / __ \/ __ `/ / __ \/ _ \
//   / __/ / /_/ / / / / / / / / /  __/  / /___/ / / / /_/ / / / / /  __/
//  /_/    \____/_/ /_/_/_/_/ /_/\___/  /_____/_/ /_/\__, /_/_/ /_/\___/
//                                                  /____/
// FOnline Engine
// https://fonline.ru
// https://github.com/cvet/fonline
//
// MIT License
//
// Copyright (c) 2006 - present, Anton Tsvetinskiy aka cvet <cvet@tut.by>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once

#include "Common.h"

#include "Critter.h"
#include "DataBase.h"
#include "Entity.h"
#include "GeometryHelper.h"
#include "Item.h"
#include "Location.h"
#include "Map.h"
#include "ServerScripting.h"
#include "Settings.h"
#include "Timer.h"

class ProtoManager;
class EntityManager;
class MapManager;
class ItemManager;

class CritterManager final
{
public:
    CritterManager() = delete;
    CritterManager(ServerSettings& settings, ProtoManager& proto_mngr, EntityManager& entity_mngr, MapManager& map_mngr, ItemManager& item_mngr, ServerScriptSystem& script_sys, GameTimer& game_time);
    CritterManager(const CritterManager&) = delete;
    CritterManager(CritterManager&&) noexcept = delete;
    auto operator=(const CritterManager&) = delete;
    auto operator=(CritterManager&&) noexcept = delete;
    ~CritterManager() = default;

    auto CreateNpc(hash proto_id, Properties* props, Map* map, ushort hx, ushort hy, uchar dir, bool accuracy) -> Npc*;
    auto RestoreNpc(uint id, hash proto_id, const DataBase::Document& doc) -> bool;
    void DeleteNpc(Critter* cr);
    void DeleteInventory(Critter* cr);

    void AddItemToCritter(Critter* cr, Item*& item, bool send);
    void EraseItemFromCritter(Critter* cr, Item* item, bool send);

    void GetCritters(CritterVec& critters);
    void GetNpcs(NpcVec& npcs);
    void GetClients(ClientVec& players, bool on_global_map);
    void GetGlobalMapCritters(ushort wx, ushort wy, uint radius, int find_type, CritterVec& critters);
    auto GetCritter(uint crid) -> Critter*;
    auto GetPlayer(uint crid) -> Client*;
    auto GetPlayer(const char* name) -> Client*;
    auto GetNpc(uint crid) -> Npc*;

    auto GetItemByPidInvPriority(Critter* cr, hash item_pid) -> Item*;

    void ProcessTalk(Client* cl, bool force);
    void CloseTalk(Client* cl);

    auto PlayersInGame() const -> uint;
    auto NpcInGame() const -> uint;
    auto CrittersInGame() const -> uint;

private:
    ServerSettings& _settings;
    GeometryHelper _geomHelper;
    ProtoManager& _protoMngr;
    EntityManager& _entityMngr;
    MapManager& _mapMngr;
    ItemManager& _itemMngr;
    ServerScriptSystem& _scriptSys;
    GameTimer& _gameTime;
    int _dummy {};
};

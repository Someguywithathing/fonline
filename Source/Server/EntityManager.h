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
#include "Item.h"
#include "Location.h"
#include "Map.h"
#include "ServerScripting.h"

class MapManager;
class CritterManager;
class ItemManager;

class EntityManager final
{
public:
    EntityManager() = delete;
    EntityManager(MapManager& map_mngr, CritterManager& cr_mngr, ItemManager& item_mngr, ServerScriptSystem& script_sys, DataBase* db_storage, GlobalVars* globs);
    EntityManager(const EntityManager&) = delete;
    EntityManager(EntityManager&&) noexcept = delete;
    auto operator=(const EntityManager&) = delete;
    auto operator=(EntityManager&&) noexcept = delete;
    ~EntityManager() = default;

    void RegisterEntity(Entity* entity);
    void UnregisterEntity(Entity* entity);
    auto GetEntity(uint id, EntityType type) -> Entity*;
    void GetEntities(EntityType type, EntityVec& entities);
    [[nodiscard]] auto GetEntitiesCount(EntityType type) const -> uint;

    void GetItems(ItemVec& items);
    void GetCritterItems(uint crid, ItemVec& items);
    auto GetCritter(uint crid) -> Critter*;
    void GetCritters(CritterVec& critters);
    auto GetMapByPid(hash pid, uint skip_count) -> Map*;
    void GetMaps(MapVec& maps);
    auto GetLocationByPid(hash pid, uint skip_count) -> Location*;
    void GetLocations(LocationVec& locs);

    auto LoadEntities() -> bool;
    void ClearEntities();

private:
    auto LinkMaps() -> bool;
    auto LinkNpc() -> bool;
    auto LinkItems() -> bool;
    void InitAfterLoad();

    MapManager& _mapMngr;
    CritterManager& _crMngr;
    ItemManager& _itemMngr;
    ServerScriptSystem& _scriptSys;
    DataBase* _dbStorage {};
    GlobalVars* _globals {};
    EntityMap _allEntities {};
    uint _entitiesCount[static_cast<int>(EntityType::Max)] {};
    int _dummy {};
};

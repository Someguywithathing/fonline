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

// Todo: add FO_API_*_VIRTUAL_PROPERTY and FO_API_*_VIRTUAL_READONLY_PROPERTY
// Todo: add supporting of components for properties
// Todo: split FO_API_SETTING by subgroups (CLIENT, SERVER, RENDER, etc)
// Todo: improve RPC calls
// Todo: add custom entities handling
// Todo: add Proto* to scripts that have readable properties
// Todo: add local entity events
// Todo: add ImGui bindings
// Todo: hex coords to single structure (hx, hy -> coord)

// Possible defines:
// FO_API_PARTLY_UNDEF
// FO_API_MULTIPLAYER_ONLY
// FO_API_SINGLEPLAYER_ONLY
// FO_API_NATIVE_ONLY
// FO_API_ANGELSCRIPT_ONLY
// FO_API_MONO_ONLY
// FO_API_ENUM_GROUP(name)
// FO_API_ENUM_ENTRY(group, name, value)
// FO_API_COMMON_EVENT(name, ...)
// FO_API_SERVER_EVENT(name, ...)
// FO_API_CLIENT_EVENT(name, ...)
// FO_API_MAPPER_EVENT(name, ...)
// FO_API_SETTING(type, name, ...)
// FO_API_GLOBAL_COMMON_IMPL
// FO_API_GLOBAL_SERVER_IMPL
// FO_API_GLOBAL_CLIENT_IMPL
// FO_API_GLOBAL_MAPPER_IMPL
// FO_API_ITEM_HEADER
// FO_API_ITEM_CLASS
// FO_API_ITEM_IMPL
// FO_API_ITEM_VIEW_HEADER
// FO_API_ITEM_VIEW_CLASS
// FO_API_ITEM_VIEW_IMPL
// FO_API_CRITTER_HEADER
// FO_API_CRITTER_CLASS
// FO_API_CRITTER_IMPL
// FO_API_CRITTER_VIEW_HEADER
// FO_API_CRITTER_VIEW_CLASS
// FO_API_CRITTER_VIEW_IMPL
// FO_API_MAP_HEADER
// FO_API_MAP_CLASS
// FO_API_MAP_IMPL
// FO_API_MAP_VIEW_HEADER
// FO_API_MAP_VIEW_CLASS
// FO_API_MAP_VIEW_IMPL
// FO_API_LOCATION_HEADER
// FO_API_LOCATION_CLASS
// FO_API_LOCATION_IMPL
// FO_API_LOCATION_VIEW_HEADER
// FO_API_LOCATION_VIEW_CLASS
// FO_API_LOCATION_VIEW_IMPL
// FO_API_GLOBAL_COMMON_FUNC(name, ret, ...)
// FO_API_GLOBAL_COMMON_FUNC_IMPL
// FO_API_GLOBAL_SERVER_FUNC(name, ret, ...)
// FO_API_GLOBAL_SERVER_FUNC_IMPL
// FO_API_GLOBAL_CLIENT_FUNC(name, ret, ...)
// FO_API_GLOBAL_CLIENT_FUNC_IMPL
// FO_API_GLOBAL_MAPPER_FUNC(name, ret, ...)
// FO_API_GLOBAL_MAPPER_FUNC_IMPL
// FO_API_GLOBAL_PROPERTY(access, type, name, ...)
// FO_API_GLOBAL_READONLY_PROPERTY(access, type, name, ...)
// FO_API_ITEM_METHOD(name, ret, ...)
// FO_API_ITEM_METHOD_IMPL
// FO_API_ITEM_VIEW_METHOD(name, ret, ...)
// FO_API_ITEM_VIEW_METHOD_IMPL
// FO_API_ITEM_PROPERTY(access, type, name, ...)
// FO_API_ITEM_READONLY_PROPERTY(access, type, name, ...)
// FO_API_CRITTER_METHOD(name, ret, ...)
// FO_API_CRITTER_METHOD_IMPL
// FO_API_CRITTER_VIEW_METHOD(name, ret, ...)
// FO_API_CRITTER_VIEW_METHOD_IMPL
// FO_API_CRITTER_PROPERTY(access, type, name, ...)
// FO_API_CRITTER_READONLY_PROPERTY(access, type, name, ...)
// FO_API_MAP_METHOD(name, ret, ...)
// FO_API_MAP_METHOD_IMPL
// FO_API_MAP_VIEW_METHOD(name, ret, ...)
// FO_API_MAP_VIEW_METHOD_IMPL
// FO_API_MAP_PROPERTY(access, type, name, ...)
// FO_API_MAP_READONLY_PROPERTY(access, type, name, ...)
// FO_API_LOCATION_METHOD(name, ret, ...)
// FO_API_LOCATION_METHOD_IMPL
// FO_API_LOCATION_VIEW_METHOD(name, ret, ...)
// FO_API_LOCATION_VIEW_METHOD_IMPL
// FO_API_LOCATION_PROPERTY(access, type, name, ...)
// FO_API_LOCATION_READONLY_PROPERTY(access, type, name, ...)
// FO_API_PROLOG(...)
// FO_API_EPILOG(...)
// FO_API_ARG(type, name)
// FO_API_ARG_ARR(type, name)
// FO_API_ARG_OBJ(type, name)
// FO_API_ARG_OBJ_ARR(type, name)
// FO_API_ARG_REF(type, name) // Todo: remove for better portability
// FO_API_ARG_ARR_REF(type, name) // Todo: remove for better portability
// FO_API_ARG_ENUM(type, name)
// FO_API_ARG_CALLBACK(type, name)
// FO_API_ARG_PREDICATE(type, name)
// FO_API_ARG_DICT(key, val, name)
// FO_API_ARG_MARSHAL(type, name)
// FO_API_ARG_ARR_MARSHAL(type, name)
// FO_API_ARG_OBJ_MARSHAL(type, name)
// FO_API_ARG_OBJ_ARR_MARSHAL(type, name)
// FO_API_ARG_REF_MARSHAL(type, name)
// FO_API_ARG_ARR_REF_MARSHAL(type, name)
// FO_API_ARG_ENUM_MARSHAL(type, name)
// FO_API_ARG_CALLBACK_MARSHAL(type, name)
// FO_API_ARG_PREDICATE_MARSHAL(type, name)
// FO_API_ARG_DICT_MARSHAL(key, val, name)
// FO_API_RET(type)
// FO_API_RET_ARR(type)
// FO_API_RET_OBJ(type)
// FO_API_RET_OBJ_ARR(type)
// FO_API_RETURN(expr)
// FO_API_RETURN_VOID()
// FO_API_PROPERTY_TYPE(type)
// FO_API_PROPERTY_TYPE_ARR(type)
// FO_API_PROPERTY_TYPE_OBJ(type)
// FO_API_PROPERTY_TYPE_OBJ_ARR(type)
// FO_API_PROPERTY_TYPE_ENUM(type)
// FO_API_PROPERTY_MOD(mod)

#ifndef FO_API_ENUM_GROUP
#define FO_API_ENUM_GROUP(...)
#endif
#ifndef FO_API_ENUM_ENTRY
#define FO_API_ENUM_ENTRY(...)
#endif
#ifndef FO_API_COMMON_EVENT
#define FO_API_COMMON_EVENT(...)
#endif
#ifndef FO_API_SERVER_EVENT
#define FO_API_SERVER_EVENT(...)
#endif
#ifndef FO_API_CLIENT_EVENT
#define FO_API_CLIENT_EVENT(...)
#endif
#ifndef FO_API_MAPPER_EVENT
#define FO_API_MAPPER_EVENT(...)
#endif
#ifndef FO_API_SETTING
#define FO_API_SETTING(...)
#endif
#ifndef FO_API_GLOBAL_COMMON_FUNC
#define FO_API_GLOBAL_COMMON_FUNC(...)
#endif
#ifndef FO_API_GLOBAL_SERVER_FUNC
#define FO_API_GLOBAL_SERVER_FUNC(...)
#endif
#ifndef FO_API_GLOBAL_CLIENT_FUNC
#define FO_API_GLOBAL_CLIENT_FUNC(...)
#endif
#ifndef FO_API_GLOBAL_MAPPER_FUNC
#define FO_API_GLOBAL_MAPPER_FUNC(...)
#endif
#ifndef FO_API_GLOBAL_PROPERTY
#define FO_API_GLOBAL_PROPERTY(...)
#endif
#ifndef FO_API_GLOBAL_READONLY_PROPERTY
#define FO_API_GLOBAL_READONLY_PROPERTY FO_API_GLOBAL_PROPERTY
#endif
#ifndef FO_API_ITEM_METHOD
#define FO_API_ITEM_METHOD(...)
#endif
#ifndef FO_API_ITEM_VIEW_METHOD
#define FO_API_ITEM_VIEW_METHOD(...)
#endif
#ifndef FO_API_ITEM_HEX_VIEW_METHOD
#define FO_API_ITEM_HEX_VIEW_METHOD(...)
#endif
#ifndef FO_API_ITEM_PROPERTY
#define FO_API_ITEM_PROPERTY(...)
#endif
#ifndef FO_API_ITEM_READONLY_PROPERTY
#define FO_API_ITEM_READONLY_PROPERTY FO_API_ITEM_PROPERTY
#endif
#ifndef FO_API_CRITTER_METHOD
#define FO_API_CRITTER_METHOD(...)
#endif
#ifndef FO_API_CRITTER_VIEW_METHOD
#define FO_API_CRITTER_VIEW_METHOD(...)
#endif
#ifndef FO_API_CRITTER_PROPERTY
#define FO_API_CRITTER_PROPERTY(...)
#endif
#ifndef FO_API_CRITTER_READONLY_PROPERTY
#define FO_API_CRITTER_READONLY_PROPERTY FO_API_CRITTER_PROPERTY
#endif
#ifndef FO_API_MAP_METHOD
#define FO_API_MAP_METHOD(...)
#endif
#ifndef FO_API_MAP_VIEW_METHOD
#define FO_API_MAP_VIEW_METHOD(...)
#endif
#ifndef FO_API_MAP_PROPERTY
#define FO_API_MAP_PROPERTY(...)
#endif
#ifndef FO_API_MAP_READONLY_PROPERTY
#define FO_API_MAP_READONLY_PROPERTY FO_API_MAP_PROPERTY
#endif
#ifndef FO_API_LOCATION_METHOD
#define FO_API_LOCATION_METHOD(...)
#endif
#ifndef FO_API_LOCATION_VIEW_METHOD
#define FO_API_LOCATION_VIEW_METHOD(...)
#endif
#ifndef FO_API_LOCATION_PROPERTY
#define FO_API_LOCATION_PROPERTY(...)
#endif
#ifndef FO_API_LOCATION_READONLY_PROPERTY
#define FO_API_LOCATION_READONLY_PROPERTY FO_API_LOCATION_PROPERTY
#endif
#ifndef FO_API_PROPERTY_TYPE
#define FO_API_PROPERTY_TYPE(type) type
#endif
#ifndef FO_API_PROPERTY_TYPE_ARR
#define FO_API_PROPERTY_TYPE_ARR(type) vector<type>
#endif
#ifndef FO_API_PROPERTY_TYPE_OBJ
#define FO_API_PROPERTY_TYPE_OBJ(type) type*
#endif
#ifndef FO_API_PROPERTY_TYPE_OBJ_ARR
#define FO_API_PROPERTY_TYPE_OBJ_ARR(type) vector<type*>
#endif
#ifndef FO_API_PROPERTY_TYPE_ENUM
#define FO_API_PROPERTY_TYPE_ENUM(type) int
#endif

#ifndef FO_API_COMMON_IMPL
#define FO_API_COMMON_IMPL 0
#endif
#ifndef FO_API_SERVER_IMPL
#define FO_API_SERVER_IMPL 0
#endif
#ifndef FO_API_CLIENT_IMPL
#define FO_API_CLIENT_IMPL 0
#endif
#ifndef FO_API_MAPPER_IMPL
#define FO_API_MAPPER_IMPL 0
#endif
#ifndef FO_API_GLOBAL_COMMON_IMPL
#define FO_API_GLOBAL_COMMON_IMPL 0
#endif
#ifndef FO_API_GLOBAL_SERVER_IMPL
#define FO_API_GLOBAL_SERVER_IMPL 0
#endif
#ifndef FO_API_GLOBAL_CLIENT_IMPL
#define FO_API_GLOBAL_CLIENT_IMPL 0
#endif
#ifndef FO_API_GLOBAL_MAPPER_IMPL
#define FO_API_GLOBAL_MAPPER_IMPL 0
#endif
#ifndef FO_API_ITEM_HEADER
#define FO_API_ITEM_HEADER 0
#endif
#ifndef FO_API_ITEM_CLASS
#define FO_API_ITEM_CLASS 0
#endif
#ifndef FO_API_ITEM_IMPL
#define FO_API_ITEM_IMPL 0
#endif
#ifndef FO_API_ITEM_VIEW_HEADER
#define FO_API_ITEM_VIEW_HEADER 0
#endif
#ifndef FO_API_ITEM_VIEW_CLASS
#define FO_API_ITEM_VIEW_CLASS 0
#endif
#ifndef FO_API_ITEM_VIEW_IMPL
#define FO_API_ITEM_VIEW_IMPL 0
#endif
#ifndef FO_API_CRITTER_HEADER
#define FO_API_CRITTER_HEADER 0
#endif
#ifndef FO_API_CRITTER_CLASS
#define FO_API_CRITTER_CLASS 0
#endif
#ifndef FO_API_CRITTER_IMPL
#define FO_API_CRITTER_IMPL 0
#endif
#ifndef FO_API_CRITTER_VIEW_HEADER
#define FO_API_CRITTER_VIEW_HEADER 0
#endif
#ifndef FO_API_CRITTER_VIEW_CLASS
#define FO_API_CRITTER_VIEW_CLASS 0
#endif
#ifndef FO_API_CRITTER_VIEW_IMPL
#define FO_API_CRITTER_VIEW_IMPL 0
#endif
#ifndef FO_API_MAP_HEADER
#define FO_API_MAP_HEADER 0
#endif
#ifndef FO_API_MAP_CLASS
#define FO_API_MAP_CLASS 0
#endif
#ifndef FO_API_MAP_IMPL
#define FO_API_MAP_IMPL 0
#endif
#ifndef FO_API_MAP_VIEW_HEADER
#define FO_API_MAP_VIEW_HEADER 0
#endif
#ifndef FO_API_MAP_VIEW_CLASS
#define FO_API_MAP_VIEW_CLASS 0
#endif
#ifndef FO_API_MAP_VIEW_IMPL
#define FO_API_MAP_VIEW_IMPL 0
#endif
#ifndef FO_API_LOCATION_HEADER
#define FO_API_LOCATION_HEADER 0
#endif
#ifndef FO_API_LOCATION_CLASS
#define FO_API_LOCATION_CLASS 0
#endif
#ifndef FO_API_LOCATION_IMPL
#define FO_API_LOCATION_IMPL 0
#endif
#ifndef FO_API_LOCATION_VIEW_HEADER
#define FO_API_LOCATION_VIEW_HEADER 0
#endif
#ifndef FO_API_LOCATION_VIEW_CLASS
#define FO_API_LOCATION_VIEW_CLASS 0
#endif
#ifndef FO_API_LOCATION_VIEW_IMPL
#define FO_API_LOCATION_VIEW_IMPL 0
#endif
#ifndef FO_API_GLOBAL_COMMON_FUNC_IMPL
#define FO_API_GLOBAL_COMMON_FUNC_IMPL 0
#endif
#ifndef FO_API_GLOBAL_SERVER_FUNC_IMPL
#define FO_API_GLOBAL_SERVER_FUNC_IMPL 0
#endif
#ifndef FO_API_GLOBAL_CLIENT_FUNC_IMPL
#define FO_API_GLOBAL_CLIENT_FUNC_IMPL 0
#endif
#ifndef FO_API_GLOBAL_MAPPER_FUNC_IMPL
#define FO_API_GLOBAL_MAPPER_FUNC_IMPL 0
#endif
#ifndef FO_API_ITEM_METHOD_IMPL
#define FO_API_ITEM_METHOD_IMPL 0
#endif
#ifndef FO_API_ITEM_VIEW_METHOD_IMPL
#define FO_API_ITEM_VIEW_METHOD_IMPL 0
#endif
#ifndef FO_API_CRITTER_METHOD_IMPL
#define FO_API_CRITTER_METHOD_IMPL 0
#endif
#ifndef FO_API_CRITTER_VIEW_METHOD_IMPL
#define FO_API_CRITTER_VIEW_METHOD_IMPL 0
#endif
#ifndef FO_API_MAP_METHOD_IMPL
#define FO_API_MAP_METHOD_IMPL 0
#endif
#ifndef FO_API_MAP_VIEW_METHOD_IMPL
#define FO_API_MAP_VIEW_METHOD_IMPL 0
#endif
#ifndef FO_API_LOCATION_METHOD_IMPL
#define FO_API_LOCATION_METHOD_IMPL 0
#endif
#ifndef FO_API_LOCATION_VIEW_METHOD_IMPL
#define FO_API_LOCATION_VIEW_METHOD_IMPL 0
#endif

#include "ScriptApi-Enums-Mirror.h"

#include "ScriptApi-Events-Mirror.h"

#include "ScriptApi-Properties-Mirror.h"

#include "ScriptApi-Common-Mirror.h"

#include "ScriptApi-Client-Mirror.h"
#include "ScriptApi-Mapper-Mirror.h"
#include "ScriptApi-Server-Mirror.h"

#include "ScriptApi-Custom-Mirror.h"

#undef FO_API_COMMON_IMPL
#undef FO_API_SERVER_IMPL
#undef FO_API_CLIENT_IMPL
#undef FO_API_MAPPER_IMPL
#undef FO_API_ENUM_GROUP
#undef FO_API_ENUM_ENTRY
#undef FO_API_COMMON_EVENT
#undef FO_API_SERVER_EVENT
#undef FO_API_CLIENT_EVENT
#undef FO_API_MAPPER_EVENT
#undef FO_API_SETTING
#undef FO_API_GLOBAL_COMMON_IMPL
#undef FO_API_GLOBAL_SERVER_IMPL
#undef FO_API_GLOBAL_CLIENT_IMPL
#undef FO_API_GLOBAL_MAPPER_IMPL
#undef FO_API_ITEM_HEADER
#undef FO_API_ITEM_CLASS
#undef FO_API_ITEM_IMPL
#undef FO_API_ITEM_VIEW_HEADER
#undef FO_API_ITEM_VIEW_CLASS
#undef FO_API_ITEM_VIEW_IMPL
#undef FO_API_CRITTER_HEADER
#undef FO_API_CRITTER_CLASS
#undef FO_API_CRITTER_IMPL
#undef FO_API_CRITTER_VIEW_HEADER
#undef FO_API_CRITTER_VIEW_CLASS
#undef FO_API_CRITTER_VIEW_IMPL
#undef FO_API_MAP_HEADER
#undef FO_API_MAP_CLASS
#undef FO_API_MAP_IMPL
#undef FO_API_MAP_VIEW_HEADER
#undef FO_API_MAP_VIEW_CLASS
#undef FO_API_MAP_VIEW_IMPL
#undef FO_API_LOCATION_HEADER
#undef FO_API_LOCATION_CLASS
#undef FO_API_LOCATION_IMPL
#undef FO_API_LOCATION_VIEW_HEADER
#undef FO_API_LOCATION_VIEW_CLASS
#undef FO_API_LOCATION_VIEW_IMPL
#undef FO_API_GLOBAL_COMMON_FUNC
#undef FO_API_GLOBAL_COMMON_FUNC_IMPL
#undef FO_API_GLOBAL_SERVER_FUNC
#undef FO_API_GLOBAL_SERVER_FUNC_IMPL
#undef FO_API_GLOBAL_CLIENT_FUNC
#undef FO_API_GLOBAL_CLIENT_FUNC_IMPL
#undef FO_API_GLOBAL_MAPPER_FUNC
#undef FO_API_GLOBAL_MAPPER_FUNC_IMPL
#undef FO_API_GLOBAL_PROPERTY
#undef FO_API_GLOBAL_READONLY_PROPERTY
#undef FO_API_ITEM_METHOD
#undef FO_API_ITEM_METHOD_IMPL
#undef FO_API_ITEM_VIEW_METHOD
#undef FO_API_ITEM_VIEW_METHOD_IMPL
#undef FO_API_ITEM_PROPERTY
#undef FO_API_ITEM_READONLY_PROPERTY
#undef FO_API_CRITTER_METHOD
#undef FO_API_CRITTER_METHOD_IMPL
#undef FO_API_CRITTER_VIEW_METHOD
#undef FO_API_CRITTER_VIEW_METHOD_IMPL
#undef FO_API_CRITTER_PROPERTY
#undef FO_API_CRITTER_READONLY_PROPERTY
#undef FO_API_MAP_METHOD
#undef FO_API_MAP_METHOD_IMPL
#undef FO_API_MAP_VIEW_METHOD
#undef FO_API_MAP_VIEW_METHOD_IMPL
#undef FO_API_MAP_PROPERTY
#undef FO_API_MAP_READONLY_PROPERTY
#undef FO_API_LOCATION_METHOD
#undef FO_API_LOCATION_METHOD_IMPL
#undef FO_API_LOCATION_VIEW_METHOD
#undef FO_API_LOCATION_VIEW_METHOD_IMPL
#undef FO_API_LOCATION_PROPERTY
#undef FO_API_LOCATION_READONLY_PROPERTY

#ifndef FO_API_PARTLY_UNDEF
#undef FO_API_PROLOG
#undef FO_API_EPILOG
#undef FO_API_ARG
#undef FO_API_ARG_ARR
#undef FO_API_ARG_OBJ
#undef FO_API_ARG_OBJ_ARR
#undef FO_API_ARG_REF
#undef FO_API_ARG_ARR_REF
#undef FO_API_ARG_ENUM
#undef FO_API_ARG_CALLBACK
#undef FO_API_ARG_PREDICATE
#undef FO_API_ARG_DICT
#undef FO_API_ARG_MARSHAL
#undef FO_API_ARG_ARR_MARSHAL
#undef FO_API_ARG_OBJ_MARSHAL
#undef FO_API_ARG_OBJ_ARR_MARSHAL
#undef FO_API_ARG_REF_MARSHAL
#undef FO_API_ARG_ARR_REF_MARSHAL
#undef FO_API_ARG_ENUM_MARSHAL
#undef FO_API_ARG_CALLBACK_MARSHAL
#undef FO_API_ARG_PREDICATE_MARSHAL
#undef FO_API_ARG_DICT_MARSHAL
#undef FO_API_RET
#undef FO_API_RET_ARR
#undef FO_API_RET_OBJ
#undef FO_API_RET_OBJ_ARR
#undef FO_API_RETURN
#undef FO_API_RETURN_VOID
#undef FO_API_PROPERTY_TYPE
#undef FO_API_PROPERTY_TYPE_ARR
#undef FO_API_PROPERTY_TYPE_OBJ
#undef FO_API_PROPERTY_TYPE_OBJ_ARR
#undef FO_API_PROPERTY_TYPE_ENUM
#undef FO_API_PROPERTY_MOD
#endif

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

#include "ConfigFile.h"
#include "StringUtils.h"

ConfigFile::ConfigFile(const string& str)
{
    ParseStr(str);
}

void ConfigFile::CollectContent()
{
    _collectContent = true;
}

void ConfigFile::AppendData(const string& str)
{
    ParseStr(str);
}

void ConfigFile::ParseStr(const string& str)
{
    StrMap* cur_app = nullptr;

    auto it_app = _appKeyValues.find("");
    if (it_app == _appKeyValues.end()) {
        auto it = _appKeyValues.insert(std::make_pair("", StrMap()));
        _appKeyValuesOrder.push_back(it);
        cur_app = &it->second;
    }
    else {
        cur_app = &it_app->second;
    }

    string app_content;
    if (_collectContent) {
        app_content.reserve(0xFFFF);
    }

    istringstream istr(str);
    string line;
    string accum_line;

    while (std::getline(istr, line, '\n')) {
        if (!line.empty()) {
            line = _str(line).trim();
        }

        // Accumulate line
        if (!accum_line.empty()) {
            line.insert(0, accum_line);
            accum_line.clear();
        }

        if (line.empty()) {
            continue;
        }

        if (line.length() >= 2 && line.back() == '\\' && (line[line.length() - 2] == ' ' || line[line.length() - 2] == '\t')) {
            line.pop_back();
            accum_line = _str(line).trim() + " ";
            continue;
        }

        // New section
        if (line[0] == '[') {
            // Parse name
            auto end = line.find(']');
            if (end == string::npos) {
                continue;
            }

            string buf = _str(line.substr(1, end - 1)).trim();
            if (buf.empty()) {
                continue;
            }

            // Store current section content
            if (_collectContent) {
                (*cur_app)[""] = app_content;
                app_content.clear();
            }

            // Add new section
            auto it = _appKeyValues.insert(std::make_pair(buf, StrMap()));
            _appKeyValuesOrder.push_back(it);
            cur_app = &it->second;
        }
        // Section content
        else {
            // Store raw content
            if (_collectContent) {
                app_content.append(line).append("\n");
            }

            // Text format {}{}{}
            if (line[0] == '{') {
                uint num = 0;
                size_t offset = 0;

                for (auto i = 0; i < 3; i++) {
                    auto first = line.find('{', offset);
                    auto last = line.find('}', first);
                    if (first == string::npos || last == string::npos) {
                        break;
                    }

                    auto str2 = line.substr(first + 1, last - first - 1);
                    offset = last + 1;

                    if (i == 0 && num == 0u) {
                        num = _str(str2).isNumber() ? _str(str2).toInt() : _str(str2).toHash();
                    }
                    else if (i == 1 && num != 0u) {
                        num += !str2.empty() ? (_str(str2).isNumber() ? _str(str2).toInt() : _str(str2).toHash()) : 0;
                    }
                    else if (i == 2 && num != 0u) {
                        (*cur_app)[_str("{}", num)] = str2;
                    }
                }
            }
            else {
                // Cut comments
                auto comment = line.find('#');
                if (comment != string::npos) {
                    line.erase(comment);
                }

                if (line.empty()) {
                    continue;
                }

                // Key value format
                auto separator = line.find('=');
                if (separator != string::npos) {
                    string key = _str(line.substr(0, separator)).trim();
                    string value = _str(line.substr(separator + 1)).trim();

                    if (!key.empty()) {
                        (*cur_app)[key] = value;
                    }
                }
            }
        }
    }
    RUNTIME_ASSERT(istr.eof());

    // Store current section content
    if (_collectContent) {
        (*cur_app)[""] = app_content;
    }
}

auto ConfigFile::SerializeData() -> string
{
    string str;
    str.reserve(100000);

    for (auto& app_it : _appKeyValuesOrder) {
        const auto& [fst, snd] = *app_it;
        if (!fst.empty()) {
            str += _str("[{}]\n", fst);
        }

        for (const auto& [fst2, snd2] : snd) {
            if (!fst2.empty()) {
                str += _str("{} = {}\n", fst2, snd2);
            }
        }

        str += "\n";
    }

    return str;
}

auto ConfigFile::GetRawValue(const string& app_name, const string& key_name) const -> const string*
{
    const auto it_app = _appKeyValues.find(app_name);
    if (it_app == _appKeyValues.end()) {
        return nullptr;
    }

    const auto it_key = it_app->second.find(key_name);
    if (it_key == it_app->second.end()) {
        return nullptr;
    }

    return &it_key->second;
}

auto ConfigFile::GetStr(const string& app_name, const string& key_name) const -> string
{
    const auto* str = GetRawValue(app_name, key_name);
    return str != nullptr ? *str : "";
}

auto ConfigFile::GetStr(const string& app_name, const string& key_name, const string& def_val) const -> string
{
    const auto* str = GetRawValue(app_name, key_name);
    return str != nullptr ? *str : def_val;
}

auto ConfigFile::GetInt(const string& app_name, const string& key_name) const -> int
{
    const auto* str = GetRawValue(app_name, key_name);
    if (str != nullptr && str->length() == 4 && _str(*str).compareIgnoreCase("true")) {
        return 1;
    }
    if (str != nullptr && str->length() == 5 && _str(*str).compareIgnoreCase("false")) {
        return 0;
    }
    return str != nullptr ? _str(*str).toInt() : 0;
}

auto ConfigFile::GetInt(const string& app_name, const string& key_name, int def_val) const -> int
{
    const auto* str = GetRawValue(app_name, key_name);
    if (str != nullptr && str->length() == 4 && _str(*str).compareIgnoreCase("true")) {
        return 1;
    }
    if (str != nullptr && str->length() == 5 && _str(*str).compareIgnoreCase("false")) {
        return 0;
    }
    return str != nullptr ? _str(*str).toInt() : def_val;
}

void ConfigFile::SetStr(const string& app_name, const string& key_name, const string& val)
{
    auto it_app = _appKeyValues.find(app_name);
    if (it_app == _appKeyValues.end()) {
        StrMap key_values;
        key_values[key_name] = val;
        const auto it = _appKeyValues.insert(std::make_pair(app_name, key_values));
        _appKeyValuesOrder.push_back(it);
    }
    else {
        it_app->second[key_name] = val;
    }
}

void ConfigFile::SetInt(const string& app_name, const string& key_name, int val)
{
    SetStr(app_name, key_name, _str("{}", val));
}

auto ConfigFile::GetApp(const string& app_name) const -> const StrMap&
{
    const auto it = _appKeyValues.find(app_name);
    RUNTIME_ASSERT(it != _appKeyValues.end());
    return it->second;
}

void ConfigFile::GetApps(const string& app_name, PStrMapVec& key_values)
{
    const auto count = _appKeyValues.count(app_name);
    auto it = _appKeyValues.find(app_name);
    key_values.reserve(key_values.size() + count);
    for (size_t i = 0; i < count; i++, ++it) {
        key_values.push_back(&it->second);
    }
}

auto ConfigFile::SetApp(const string& app_name) -> StrMap&
{
    auto it = _appKeyValues.insert(std::make_pair(app_name, StrMap()));
    _appKeyValuesOrder.push_back(it);
    return it->second;
}

auto ConfigFile::IsApp(const string& app_name) const -> bool
{
    const auto it_app = _appKeyValues.find(app_name);
    return it_app != _appKeyValues.end();
}

auto ConfigFile::IsKey(const string& app_name, const string& key_name) const -> bool
{
    const auto it_app = _appKeyValues.find(app_name);
    if (it_app == _appKeyValues.end()) {
        return false;
    }
    return it_app->second.find(key_name) != it_app->second.end();
}

void ConfigFile::GetAppNames(StrSet& apps) const
{
    for (const auto& [key, value] : _appKeyValues) {
        apps.insert(key);
    }
}

void ConfigFile::GotoNextApp(const string& app_name)
{
    const auto it_app = _appKeyValues.find(app_name);
    if (it_app == _appKeyValues.end()) {
        return;
    }

    const auto it = std::find(_appKeyValuesOrder.begin(), _appKeyValuesOrder.end(), it_app);
    RUNTIME_ASSERT(it != _appKeyValuesOrder.end());
    _appKeyValuesOrder.erase(it);
    _appKeyValues.erase(it_app);
}

auto ConfigFile::GetAppKeyValues(const string& app_name) -> const StrMap*
{
    auto it_app = _appKeyValues.find(app_name);
    return it_app != _appKeyValues.end() ? &it_app->second : nullptr;
}

auto ConfigFile::GetAppContent(const string& app_name) -> string
{
    RUNTIME_ASSERT(_collectContent);

    auto it_app = _appKeyValues.find(app_name);
    if (it_app == _appKeyValues.end()) {
        return nullptr;
    }

    const auto it_key = it_app->second.find("");
    return it_key != it_app->second.end() ? it_key->second : "";
}

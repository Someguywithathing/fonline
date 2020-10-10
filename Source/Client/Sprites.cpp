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

// Todo: exclude sprite cut system?

#include "Sprites.h"
#include "Settings.h"
#include "SpriteManager.h"

SpriteVec Sprites::_spritesPool;

void Sprite::Unvalidate()
{
    if (!Valid) {
        return;
    }
    Valid = false;

    if (ValidCallback != nullptr) {
        *ValidCallback = false;
        ValidCallback = nullptr;
    }

    if (Parent != nullptr) {
        Parent->Child = nullptr;
        Parent->Unvalidate();
    }
    if (Child != nullptr) {
        Child->Parent = nullptr;
        Child->Unvalidate();
    }

    if (ExtraChainRoot != nullptr) {
        *ExtraChainRoot = ExtraChainChild;
    }
    if (ExtraChainParent != nullptr) {
        ExtraChainParent->ExtraChainChild = ExtraChainChild;
    }
    if (ExtraChainChild != nullptr) {
        ExtraChainChild->ExtraChainParent = ExtraChainParent;
    }
    if (ExtraChainRoot != nullptr && ExtraChainChild != nullptr) {
        ExtraChainChild->ExtraChainRoot = ExtraChainRoot;
    }
    ExtraChainRoot = nullptr;
    ExtraChainParent = nullptr;
    ExtraChainChild = nullptr;

    if (MapSpr != nullptr) {
        // Todo: MapSprite releasing
        // MapSpr->Release();
        MapSpr = nullptr;
    }

    Root->_unvalidatedSprites.push_back(this);

    if (ChainRoot != nullptr) {
        *ChainRoot = ChainChild;
    }
    if (ChainLast != nullptr) {
        *ChainLast = ChainParent;
    }
    if (ChainParent != nullptr) {
        ChainParent->ChainChild = ChainChild;
    }
    if (ChainChild != nullptr) {
        ChainChild->ChainParent = ChainParent;
    }
    if (ChainRoot != nullptr && ChainChild != nullptr) {
        ChainChild->ChainRoot = ChainRoot;
    }
    if (ChainLast != nullptr && ChainParent != nullptr) {
        ChainParent->ChainLast = ChainLast;
    }
    ChainRoot = nullptr;
    ChainLast = nullptr;
    ChainParent = nullptr;
    ChainChild = nullptr;

    Root = nullptr;
}

auto Sprite::GetIntersected(int ox, int oy) -> Sprite*
{
    // Check for cutting
    if (ox < 0 || oy < 0) {
        return nullptr;
    }
    if (CutType == 0) {
        return Root->_sprMngr.IsPixNoTransp(PSprId != nullptr ? *PSprId : SprId, ox, oy, true) ? this : nullptr;
    }

    // Find root sprite
    auto* spr = this;
    while (spr->Parent != nullptr) {
        spr = spr->Parent;
    }

    // Check sprites
    const auto oxf = static_cast<float>(ox) * Root->_settings.SpritesZoom;
    while (spr != nullptr) {
        if (oxf >= spr->CutX && oxf < spr->CutX + spr->CutW) {
            return Root->_sprMngr.IsPixNoTransp(spr->PSprId != nullptr ? *spr->PSprId : spr->SprId, ox, oy, true) ? spr : nullptr;
        }
        spr = spr->Child;
    }
    return nullptr;
}

void Sprite::SetEgg(int egg)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    EggType = egg;
    if (Parent != nullptr) {
        Parent->SetEgg(egg);
    }
    if (Child != nullptr) {
        Child->SetEgg(egg);
    }
    Valid = true;
}

void Sprite::SetContour(int contour)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    ContourType = contour;
    if (Parent != nullptr) {
        Parent->SetContour(contour);
    }
    if (Child != nullptr) {
        Child->SetContour(contour);
    }
    Valid = true;
}

void Sprite::SetContour(int contour, uint color)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    ContourType = contour;
    ContourColor = color;
    if (Parent != nullptr) {
        Parent->SetContour(contour, color);
    }
    if (Child != nullptr) {
        Child->SetContour(contour, color);
    }
    Valid = true;
}

void Sprite::SetColor(uint color)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    Color = color;
    if (Parent != nullptr) {
        Parent->SetColor(color);
    }
    if (Child != nullptr) {
        Child->SetColor(color);
    }
    Valid = true;
}

void Sprite::SetAlpha(uchar* alpha)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    Alpha = alpha;
    if (Parent != nullptr) {
        Parent->SetAlpha(alpha);
    }
    if (Child != nullptr) {
        Child->SetAlpha(alpha);
    }
    Valid = true;
}

void Sprite::SetFlash(uint mask)
{
    if (!Valid) {
        return;
    }

    Valid = false;
    FlashMask = mask;
    if (Parent != nullptr) {
        Parent->SetFlash(mask);
    }
    if (Child != nullptr) {
        Child->SetFlash(mask);
    }
    Valid = true;
}

void Sprite::SetLight(int corner, uchar* light, int maxhx, int maxhy)
{
    if (!Valid) {
        return;
    }

    Valid = false;

    if (HexX >= 1 && HexX < maxhx - 1 && HexY >= 1 && HexY < maxhy - 1) {
        Light = &light[HexY * maxhx * 3 + HexX * 3];

        switch (corner) {
        default:
        case CORNER_EAST_WEST:
        case CORNER_EAST:
            LightRight = Light - 3;
            LightLeft = Light + 3;
            break;
        case CORNER_NORTH_SOUTH:
        case CORNER_WEST:
            LightRight = Light + maxhx * 3;
            LightLeft = Light - maxhx * 3;
            break;
        case CORNER_SOUTH:
            LightRight = Light - 3;
            LightLeft = Light - maxhx * 3;
            break;
        case CORNER_NORTH:
            LightRight = Light + maxhx * 3;
            LightLeft = Light + 3;
            break;
        }
    }
    else {
        Light = nullptr;
        LightRight = nullptr;
        LightLeft = nullptr;
    }

    if (Parent != nullptr) {
        Parent->SetLight(corner, light, maxhx, maxhy);
    }
    if (Child != nullptr) {
        Child->SetLight(corner, light, maxhx, maxhy);
    }

    Valid = true;
}

void Sprite::SetFixedAlpha(uchar alpha)
{
    if (!Valid) {
        return;
    }

    Valid = false;

    Alpha = reinterpret_cast<uchar*>(&Color) + 3;
    *Alpha = alpha;

    if (Parent != nullptr) {
        Parent->SetFixedAlpha(alpha);
    }
    if (Child != nullptr) {
        Child->SetFixedAlpha(alpha);
    }

    Valid = true;
}

void Sprites::GrowPool()
{
    _spritesPool.reserve(_spritesPool.size() + SPRITES_POOL_GROW_SIZE);
    for (uint i = 0; i < SPRITES_POOL_GROW_SIZE; i++) {
        _spritesPool.push_back(new Sprite());
    }
}

auto Sprites::RootSprite() -> Sprite*
{
    NON_CONST_METHOD_HINT(_spriteCount);

    return _rootSprite;
}

auto Sprites::PutSprite(Sprite* child, int draw_order, int hx, int hy, int cut, int x, int y, int* sx, int* sy, uint id, uint* id_ptr, short* ox, short* oy, uchar* alpha, RenderEffect** effect, bool* callback) -> Sprite&
{
    _spriteCount++;

    Sprite* spr = nullptr;
    if (!_unvalidatedSprites.empty()) {
        spr = _unvalidatedSprites.back();
        _unvalidatedSprites.pop_back();
    }
    else {
        if (_spritesPool.empty()) {
            GrowPool();
        }

        spr = _spritesPool.back();
        _spritesPool.pop_back();
    }

    spr->Root = this;

    if (child == nullptr) {
        if (_lastSprite == nullptr) {
            _rootSprite = spr;
            _lastSprite = spr;
            spr->ChainRoot = &_rootSprite;
            spr->ChainLast = &_lastSprite;
            spr->ChainParent = nullptr;
            spr->ChainChild = nullptr;
            spr->TreeIndex = 0;
        }
        else {
            spr->ChainParent = _lastSprite;
            spr->ChainChild = nullptr;
            _lastSprite->ChainChild = spr;
            _lastSprite->ChainLast = nullptr;
            spr->ChainLast = &_lastSprite;
            spr->TreeIndex = _lastSprite->TreeIndex + 1;
            _lastSprite = spr;
        }
    }
    else {
        spr->ChainChild = child;
        spr->ChainParent = child->ChainParent;
        child->ChainParent = spr;
        if (spr->ChainParent != nullptr) {
            spr->ChainParent->ChainChild = spr;
        }

        // Recalculate indices
        auto index = spr->ChainParent != nullptr ? spr->ChainParent->TreeIndex + 1 : 0;
        auto* spr_ = spr;
        while (spr_ != nullptr) {
            spr_->TreeIndex = index;
            spr_ = spr_->ChainChild;
            index++;
        }

        if (spr->ChainParent == nullptr) {
            RUNTIME_ASSERT(child->ChainRoot);
            _rootSprite = spr;
            spr->ChainRoot = &_rootSprite;
            child->ChainRoot = nullptr;
        }
    }

    spr->HexX = hx;
    spr->HexY = hy;
    spr->CutType = 0;
    spr->ScrX = x;
    spr->ScrY = y;
    spr->PScrX = sx;
    spr->PScrY = sy;
    spr->SprId = id;
    spr->PSprId = id_ptr;
    spr->OffsX = ox;
    spr->OffsY = oy;
    spr->Alpha = alpha;
    spr->Light = nullptr;
    spr->LightRight = nullptr;
    spr->LightLeft = nullptr;
    spr->Valid = true;
    spr->ValidCallback = callback;
    if (callback != nullptr) {
        *callback = true;
    }
    spr->EggType = 0;
    spr->ContourType = 0;
    spr->ContourColor = 0;
    spr->Color = 0;
    spr->FlashMask = 0;
    spr->DrawEffect = effect;
    spr->Parent = nullptr;
    spr->Child = nullptr;

    // Cutting
    if (cut == SPRITE_CUT_HORIZONTAL || cut == SPRITE_CUT_VERTICAL) {
        const auto hor = cut == SPRITE_CUT_HORIZONTAL;

        auto stepi = _settings.MapHexWidth / 2;
        if (_settings.MapHexagonal && hor) {
            stepi = (_settings.MapHexWidth + _settings.MapHexWidth / 2) / 2;
        }
        const auto stepf = static_cast<float>(stepi);

        const auto* si = _sprMngr.GetSpriteInfo(id_ptr != nullptr ? *id_ptr : id);
        if (si == nullptr || si->Width < stepi * 2) {
            return *spr;
        }

        spr->CutType = cut;

        int h1 = 0;
        int h2 = 0;
        if (hor) {
            h1 = spr->HexX + si->Width / 2 / stepi;
            h2 = spr->HexX - si->Width / 2 / stepi - (si->Width / 2 % stepi != 0 ? 1 : 0);
            spr->HexX = h1;
        }
        else {
            h1 = spr->HexY - si->Width / 2 / stepi;
            h2 = spr->HexY + si->Width / 2 / stepi + (si->Width / 2 % stepi != 0 ? 1 : 0);
            spr->HexY = h1;
        }

        const auto widthf = static_cast<float>(si->Width);
        auto xx = 0.0f;
        auto* parent = spr;
        for (auto i = h1;;) {
            auto ww = stepf;
            if (xx + ww > widthf) {
                ww = widthf - xx;
            }

            auto& spr_ = i != h1 ? PutSprite(nullptr, draw_order, hor ? i : hx, hor ? hy : i, 0, x, y, sx, sy, id, id_ptr, ox, oy, alpha, effect, nullptr) : *spr;
            if (i != h1) {
                spr_.Parent = parent;
            }
            parent->Child = &spr_;
            parent = &spr_;

            spr_.CutX = xx;
            spr_.CutW = ww;
            spr_.CutTexL = si->SprRect.L + (si->SprRect.R - si->SprRect.L) * (xx / widthf);
            spr_.CutTexR = si->SprRect.L + (si->SprRect.R - si->SprRect.L) * ((xx + ww) / widthf);
            spr_.CutType = cut;

            if (_settings.ShowSpriteCuts) {
                spr_.CutOyL = (hor ? -6 : -12) * ((hor ? hx : hy) - i);
                spr_.CutOyR = spr_.CutOyL;
                if (ww < stepf) {
                    spr_.CutOyR += static_cast<int>((hor ? 3.6f : -8.0f) * (1.0f - ww / stepf));
                }
            }

            xx += stepf;
            if (xx > widthf) {
                break;
            }

            if (hor && --i < h2 || !hor && ++i > h2) {
                break;
            }
        }
    }

    // Draw order
    spr->DrawOrderType = draw_order;
    spr->DrawOrderPos = draw_order >= DRAW_ORDER_FLAT && draw_order < DRAW_ORDER ? spr->HexY * MAXHEX_MAX + spr->HexX + MAXHEX_MAX * MAXHEX_MAX * (draw_order - DRAW_ORDER_FLAT) : MAXHEX_MAX * MAXHEX_MAX * DRAW_ORDER + spr->HexY * DRAW_ORDER * MAXHEX_MAX + spr->HexX * DRAW_ORDER + (draw_order - DRAW_ORDER);

    return *spr;
}

auto Sprites::AddSprite(int draw_order, int hx, int hy, int cut, int x, int y, int* sx, int* sy, uint id, uint* id_ptr, short* ox, short* oy, uchar* alpha, RenderEffect** effect, bool* callback) -> Sprite&
{
    return PutSprite(nullptr, draw_order, hx, hy, cut, x, y, sx, sy, id, id_ptr, ox, oy, alpha, effect, callback);
}

auto Sprites::InsertSprite(int draw_order, int hx, int hy, int cut, int x, int y, int* sx, int* sy, uint id, uint* id_ptr, short* ox, short* oy, uchar* alpha, RenderEffect** effect, bool* callback) -> Sprite&
{
    // For cutted sprites need resort all tree
    if (cut == SPRITE_CUT_HORIZONTAL || cut == SPRITE_CUT_VERTICAL) {
        auto& spr = PutSprite(nullptr, draw_order, hx, hy, cut, x, y, sx, sy, id, id_ptr, ox, oy, alpha, effect, callback);
        SortByMapPos();
        return spr;
    }

    // Find place
    uint index = 0;
    const uint pos = draw_order >= DRAW_ORDER_FLAT && draw_order < DRAW_ORDER ? hy * MAXHEX_MAX + hx + MAXHEX_MAX * MAXHEX_MAX * (draw_order - DRAW_ORDER_FLAT) : MAXHEX_MAX * MAXHEX_MAX * DRAW_ORDER + hy * DRAW_ORDER * MAXHEX_MAX + hx * DRAW_ORDER + (draw_order - DRAW_ORDER);

    auto* parent = _rootSprite;
    while (parent != nullptr) {
        if (!parent->Valid) {
            continue;
        }
        if (pos < parent->DrawOrderPos) {
            break;
        }
        parent = parent->ChainChild;
    }

    return PutSprite(parent, draw_order, hx, hy, cut, x, y, sx, sy, id, id_ptr, ox, oy, alpha, effect, callback);
}

void Sprites::Unvalidate()
{
    while (_rootSprite != nullptr) {
        _rootSprite->Unvalidate();
    }
    _spriteCount = 0;
}

void Sprites::SortByMapPos()
{
    if (_rootSprite == nullptr) {
        return;
    }

    SpriteVec sprites;
    sprites.reserve(_spriteCount);
    auto* spr = _rootSprite;
    while (spr != nullptr) {
        sprites.push_back(spr);
        spr = spr->ChainChild;
    }

    auto& spr_infos = _sprMngr.GetSpritesInfo();
    std::sort(sprites.begin(), sprites.end(), [&spr_infos](Sprite* spr1, Sprite* spr2) {
        const auto* si1 = spr_infos[spr1->PSprId != nullptr ? *spr1->PSprId : spr1->SprId];
        const auto* si2 = spr_infos[spr2->PSprId != nullptr ? *spr2->PSprId : spr2->SprId];
        return si1 != nullptr && si2 != nullptr && si1->Atlas != nullptr && si2->Atlas != nullptr && si1->Atlas->MainTex < si2->Atlas->MainTex;
    });

    std::sort(sprites.begin(), sprites.end(), [](Sprite* spr1, Sprite* spr2) {
        if (spr1->DrawOrderPos == spr2->DrawOrderPos) {
            return spr1->TreeIndex < spr2->TreeIndex;
        }
        return spr1->DrawOrderPos < spr2->DrawOrderPos;
    });

    for (auto& sprite : sprites) {
        sprite->ChainParent = nullptr;
        sprite->ChainChild = nullptr;
        sprite->ChainRoot = nullptr;
        sprite->ChainLast = nullptr;
    }

    for (size_t i = 1; i < sprites.size(); i++) {
        sprites[i - 1]->ChainChild = sprites[i];
        sprites[i]->ChainParent = sprites[i - 1];
    }

    _rootSprite = sprites.front();
    _lastSprite = sprites.back();
    _rootSprite->ChainRoot = &_rootSprite;
    _lastSprite->ChainLast = &_lastSprite;
}

auto Sprites::Size() const -> uint
{
    return _spriteCount;
}

void Sprites::Clear()
{
    Unvalidate();

    for (auto* spr : _unvalidatedSprites) {
        _spritesPool.push_back(spr);
    }
    _unvalidatedSprites.clear();
}

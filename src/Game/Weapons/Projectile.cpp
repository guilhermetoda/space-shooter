//
//  Projectile.cpp
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "Projectile.h"
#include "screen.h"
#include "Actor.h"

Projectile::Projectile(): mnoptrSpriteSheet(nullptr), mActive(false)
{
    
}

bool const Projectile::HasCollided(const Actor& actor) const
{
    if (mBBox.Intersects(actor.mSprite.GetBoundingBox()))
    {
        return true;
    }
    return false;
}


void Projectile::Init(const SpriteSheet* noptrSpriteSheet, const std::string& spriteName, const Vec2D& direction, float speed, const Vec2D& initialPosition, unsigned int width, unsigned int height)
{
    mnoptrSpriteSheet = noptrSpriteSheet;
    mWidth = width;
    mHeight = height;
    mBBox = { initialPosition, mWidth, mHeight };
    mTimeAlive = 0.0f;
    mFoward = direction;
    mSpeed = speed;
    mLifeTime = 5.0f;
    mSpriteName = spriteName;
    mActive = true;
    mOrigin = PLAYER;
}

void Projectile::Update(uint32_t dt)
{
    
    if (mActive && (mTimeAlive < mLifeTime))
    {
        mTimeAlive += MsToSec(dt);
        Vec2D delta = mFoward * mSpeed * MsToSec(dt);
        mBBox.MoveBy(delta);
    }
    else
    {
        mActive = false;
    }
    
}


void Projectile::Draw(Screen& screen)
{
    if (mnoptrSpriteSheet)
    {
        screen.Draw(*mnoptrSpriteSheet, mSpriteName, mBBox.GetTopLeftPoint());
    }
}

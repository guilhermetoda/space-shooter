//
//  Actor.cpp
//  Shooter
//
//  Created by Guilherme Toda on 30/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "Actor.h"
#include "Utils.h"
#include "Projectile.h"

void Actor::Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion, const std::string& explosionSpriteName)
{
    mSprite.Init(animationsPath, sprite);
    mSprite.SetPosition(initialPos);
    mVelocity = Vec2D::Zero;
    mMovementSpeed = speed;
    
    
    //mExplosionSprite.Init(animationsPath, sprite);
    mExplosionSpriteName = explosionSpriteName;
    mHasExplosion = hasExplosion;
    
    mAlive = true;
    mActive = true;
}

void Actor::Update(uint32_t dt)
{
 
    if (mIsMoving)
    {
        Vec2D delta = Vec2D::Zero;

        delta = Vec2D(mVelocity.GetX() * mMovementSpeed.GetX(), mVelocity.GetY() * mMovementSpeed.GetY());

        mDelta += delta * MsToSec(dt);
        mSprite.MoveBy(delta);
        
    }
    if (IsActive() && !IsAlive())
    {
        if (mSprite.IsFinishedPlayingAnimation())
        {
            mActive = false;
        }
    }
    mSprite.Update(dt);
}

void Actor::Draw(Screen& screen)
{
    if (IsActive())
    {
        mSprite.Draw(screen);
    }
}


void Actor::Stop()
{
    mIsMoving = false;
    mVelocity = Vec2D::Zero;
    mSprite.Stop();
}

void Actor::SetAnimation(const std::string& animationName, bool looped)
{
    mSprite.SetAnimation(animationName, looped);
}

const Vec2D Actor::GetMiddlePosition() const
{
    Vec2D topLeftPosition = GetPosition();
    topLeftPosition.SetX(topLeftPosition.GetX() + (mSprite.Size().GetX() / 2) - 5);
    topLeftPosition.SetY(topLeftPosition.GetY() - 5);
    return topLeftPosition;
}


void Actor::Shoot()
{
    
}

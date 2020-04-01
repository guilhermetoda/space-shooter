//
//  PlayerShip.cpp
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "PlayerShip.h"
#include "NormalBlaster.h"

void PlayerShip::Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed)
{
    Actor::Init(sprite, animationsPath, initialPos, speed);
    Vec2D playerFoward = { 0, 1 };
    SetFowardDirection(playerFoward);
    
    
    //Setting Normal Weapon
    std::unique_ptr<NormalBlaster> blasterPtr = std::make_unique<NormalBlaster>();
    mCurrentWeapon = std::move(blasterPtr);
    mCurrentWeapon->Init();
    mCurrentWeapon->mProjectile.Init(&sprite, "bullets_laser_large", Vec2D(0,-1), 200.0f, GetPosition(), 9, 29);
    
}
void PlayerShip::Update(uint32_t dt)
{
    const AARectangle& aaRect = mSprite.GetBoundingBox();
    
    // Check X Boundaries
    if(IsGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetX()))
    {
        if (GetVelocity().GetX() < 0)
        {
            SetVelocity(Vec2D(0.0f, GetVelocity().GetY()));
        }
    }
    else if (IsGreaterThanOrEqual(aaRect.GetBottomRightPoint().GetX(), mBoundary.GetBottomRightPoint().GetX())) {
        if (GetVelocity().GetX() > 0)
        {
            SetVelocity(Vec2D(0.0f, GetVelocity().GetY()));
        }
    }
    // Check Y Boundaries
    if (IsGreaterThanOrEqual(aaRect.GetBottomRightPoint().GetY(), mBoundary.GetBottomRightPoint().GetY())) {
        if (GetVelocity().GetY() > 0)
        {
            SetVelocity(Vec2D(GetVelocity().GetX(), 0.0f));
        }
    }
    else if (IsGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetY(), aaRect.GetTopLeftPoint().GetY())) {
        if (GetVelocity().GetY() < 0)
        {
            SetVelocity(Vec2D(GetVelocity().GetX(), 0.0f));
        }
    }
    Actor::Update(dt);
    mCurrentWeapon->Update(dt, GetPosition());
}

void PlayerShip::Fire()
{
    mCurrentWeapon->StartFire();
    std::cout<< "START FIRE" << std::endl;
}

void PlayerShip::StopFire()
{
    mCurrentWeapon->StopFire();
}

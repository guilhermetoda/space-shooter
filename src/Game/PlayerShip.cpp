//
//  PlayerShip.cpp
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "PlayerShip.h"
#include "NormalBlaster.h"
#include "GameUtils.h"
#include "Utils.h"

void PlayerShip::Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion, const std::string& explosionSpriteName)
{
    Actor::Init(sprite, animationsPath, initialPos, speed);
    Vec2D playerFoward = { 0, 1 };
    SetFowardDirection(playerFoward);
    mSprite.SetAnimation("ship_idle", true);
    
    mPlayerDirectionBits = 0000;
    SetMoving(true);
    //Setting Normal Weapon
    std::unique_ptr<Weapon> blasterPtr = std::make_unique<NormalBlaster>();
    mCurrentWeapon = std::move(blasterPtr);
    mCurrentWeapon->Init();
    mCurrentWeapon->mProjectile.Init(&sprite, "bullets_laser_large", Vec2D(0,-1), 400.0f, GetPosition(), 9, 29);
    
}
void PlayerShip::Update(uint32_t dt)
{
    const AARectangle& aaRect = mSprite.GetBoundingBox();
    SetVelocity(GetDirections());
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
    
    if ((mPlayerDirectionBits << 2) == 0)
    {
        SetAnimation("ship_idle", false);
    }
    
    Actor::Update(dt);
    mCurrentWeapon->Update(dt, GetMiddlePosition());
}

void PlayerShip::SetDirection(unsigned char newDirection)
{
    mPlayerDirectionBits |= newDirection;
}

const Vec2D PlayerShip::GetDirections() const
{
    //Moving Up
    int8_t verticalMovement = (mPlayerDirectionBits & DOWN_DIR_MASK) - (mPlayerDirectionBits & UP_DIR_MASK);
    int8_t horizontalMovement = (mPlayerDirectionBits & RIGHT_DIR_MASK) - (mPlayerDirectionBits & LEFT_DIR_MASK);
    std::cout << Vec2D(horizontalMovement, verticalMovement);
    return Vec2D(Clamp(horizontalMovement, -1, 1), Clamp(verticalMovement, -1, 1));
}

void PlayerShip::Fire()
{
    mCurrentWeapon->StartFire();
}

void PlayerShip::StopFire()
{
    mCurrentWeapon->StopFire();
}

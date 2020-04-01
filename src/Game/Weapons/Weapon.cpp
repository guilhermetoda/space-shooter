//
//  Weapon.cpp
//  Shooter
//
//  Created by Guilherme Toda on 01/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "Weapon.h"
#include "Utils.h"
#include "ShooterGame.h"
template class Pool<Projectile>;


Weapon::Weapon(): mRoundsPerMinute(0.0f), mFiringNow(false), mFireCooldown(0.0f), mWeaponFireStartPosition(Vec2D::Zero)
{
    
}

void Weapon::Init()
{
    
}

void Weapon::Update(uint32_t dt, const Vec2D& weaponPosition)
{
    mWeaponFireStartPosition = weaponPosition;
    mFireCooldown -= MsToSec(dt);
    if (mFiringNow && mFireCooldown <= 0.0f)
    {
        Fire();
        mFireCooldown = 60.0f / mRoundsPerMinute;
    }
    
    if (mFiringNow) {
        std::cout << mFireCooldown << std::endl;
        std::cout << mFiringNow << std::endl;
        
    }
}

void Weapon::Fire()
{
    Projectile& projectile = ShooterGame::mProjectilePool.AddToPool();
    
    projectile.Init(mProjectile.mnoptrSpriteSheet,mProjectile.mSpriteName, mProjectile.mFoward, mProjectile.mSpeed, mWeaponFireStartPosition, mProjectile.mWidth, mProjectile.mHeight);
}

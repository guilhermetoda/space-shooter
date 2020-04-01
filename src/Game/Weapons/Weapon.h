//
//  Weapon.h
//  Shooter
//
//  Created by Guilherme Toda on 01/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Weapon_h
#define Weapon_h

#include <stdint.h>
#include "Projectile.h"
#include "Vec2D.h"

class Weapon
{
public:
    virtual ~Weapon() {};
    Weapon();
    virtual void Init();
    virtual void Update(uint32_t dt, const Vec2D& weaponPosition);
    
    virtual void Fire();
    
    inline void StartFire() { mFiringNow = true; }
    inline void StopFire() { mFiringNow = false; }
    
    inline const bool IsFiring() const { return mFiringNow; }
    inline void SetPosition(const Vec2D& position) { mWeaponFireStartPosition = position; }
    
    Projectile mProjectile;
protected:
    float mRoundsPerMinute;
    Vec2D mWeaponFireStartPosition;
    //Color mBulletColor;
private:
    float mFireCooldown;
    bool mFiringNow;
    
};

#endif /* Weapon_h */

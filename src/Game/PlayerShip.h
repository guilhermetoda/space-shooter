//
//  PlayerShip.h
//  Shooter
//
//  Created by Guilherme Toda on 30/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef PlayerShip_h
#define PlayerShip_h
#include "Actor.h"
#include "AARectangle.h"
#include "Weapon.h"
#include <memory>

class SpriteSheet;
class Screen;
class Vec2D;

class PlayerShip : public Actor
{
public:
    virtual void Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed) override;
    virtual void Update(uint32_t dt) override;
    
    inline void SetBoundary(const AARectangle& boundary) { mBoundary = boundary; }
    inline AARectangle GetBoundary() { return mBoundary; }
    
    void Fire();
    void StopFire();
    
private:
    AARectangle mBoundary;
    std::unique_ptr<Weapon> mCurrentWeapon;
};

#endif /* PlayerShip_h */

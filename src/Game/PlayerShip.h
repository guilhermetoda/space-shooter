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

/* Player Movement is now using bitwise operators
   one bit for each direction,
   example: 1000 (8) goes up
            0100 (4) goes down
            0110 (6) goes left and down
 */

class SpriteSheet;
class Screen;
class Vec2D;

class PlayerShip : public Actor
{
public:
    virtual void Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion = false, const std::string& explosionSpriteName = "") override;
    virtual void Update(uint32_t dt) override;
    
    inline void SetBoundary(const AARectangle& boundary) { mBoundary = boundary; }
    inline AARectangle GetBoundary() { return mBoundary; }
    void SetDirection(unsigned char newDirection);
    inline void UnsetDirection(unsigned char unsettedDirection) { mPlayerDirectionBits &= ~unsettedDirection; }
        
    const Vec2D GetDirections() const;
    
    void Fire();
    void StopFire();
    
private:
    AARectangle mBoundary;
    std::unique_ptr<Weapon> mCurrentWeapon;
    unsigned char mPlayerDirectionBits;
};

#endif /* PlayerShip_h */

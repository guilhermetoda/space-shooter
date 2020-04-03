//
//  FollowPlayerEnemy.h
//  Shooter
//
//  Created by Guilherme Toda on 03/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef FollowPlayerEnemy_h
#define FollowPlayerEnemy_h

#include "Actor.h"
#include "Vec2D.h"
//#include "AARectangle.h"
//#include "Weapon.h"

class SpriteSheet;
class Screen;
class Vec2D;

class Enemy : public Actor
{
public:
    virtual void Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion = false, const std::string& explosionSpriteName = "") override;
    virtual void Update(uint32_t dt) override;
    inline void SetFollowPlayer(bool toFollow) { mFollowPlayer = toFollow; }
    
private:
    bool CheckCollision();
    Vec2D mTargetPosition;
};


#endif /* FollowPlayerEnemy_h */

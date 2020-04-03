//
//  FollowTarget.h
//  Shooter
//
//  Created by Guilherme Toda on 03/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef FollowTarget_h
#define FollowTarget_h

#include "Actor.h"
#include "Vec2D.h"
#include <memory>
//#include "AARectangle.h"
//#include "Weapon.h"

class SpriteSheet;
class Screen;
class Vec2D;

class FollowTarget: public Actor
{
public:
    virtual void Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion = false, const std::string& explosionSpriteName = "") override;
    virtual void Update(uint32_t dt) override;
    void SetActorToFollow(Actor& actor);
private:
    bool CheckCollision();
    Actor *mnoptrTarget;
};


#endif /* FollowTarget_h */

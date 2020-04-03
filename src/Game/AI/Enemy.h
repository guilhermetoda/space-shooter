//
//  Enemy.h
//  Shooter
//
//  Created by Guilherme Toda on 01/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#include "Actor.h"
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
    
};


#endif /* Enemy_h */

//
//  Projectile.h
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Projectile_h
#define Projectile_h

#include <stdint.h>
#include "Vec2D.h"
#include "SpriteSheet.h"
#include "AARectangle.h"
#include <string.h>

class Screen;

class Projectile
{
public:
    Projectile();
    virtual void Init(const SpriteSheet* noptrSpriteSheet, const std::string& spriteName, const Vec2D& direction, float speed, const Vec2D& initialPosition, unsigned int width, unsigned int height);
    virtual void Update(uint32_t dt);
    virtual void Draw(Screen& screen);
    
    inline const bool IsActive() const{ return mActive; }
private:
    const SpriteSheet* mnoptrSpriteSheet;
    std::string mSpriteName;
    Vec2D mFoward;
    float mSpeed;
    float mLifeTime;
    AARectangle mBBox;
    
    unsigned int mWidth;
    unsigned int mHeight;
    
    float mTimeAlive;
    
    bool mActive;
    
    friend class Weapon;
};

#endif /* Projectile_h */

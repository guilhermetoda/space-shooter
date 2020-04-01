//
//  Actor.h
//  Shooter
//
//  Created by Guilherme Toda on 30/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Actor_h
#define Actor_h

#include "GameUtils.h"
#include "AnimatedSprite.h"
#include "Vec2D.h"
#include "AARectangle.h"

class Actor
{
public:
    virtual ~Actor() {};
    virtual void Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed);
    virtual void Draw(Screen& screen);
    virtual void Update(uint32_t dt);
    virtual void Stop();
    
    inline void SetVelocity(Vec2D newVelocity) { mVelocity =  newVelocity; }
    inline const Vec2D GetVelocity() const { return mVelocity; }
    
    inline void SetMovement(MovementDirections direction, bool isMoving) { mIsMoving = isMoving; }
    void SetAnimation(const std::string& animationName, bool looped);
    
    void SetFowardDirection(const Vec2D& foward) { mFowardDirection = foward; }
    inline const Vec2D GetFowardDirection() const { return mFowardDirection; }
    
    inline const Vec2D GetPosition() const {  return mSprite.GetBoundingBox().GetTopLeftPoint(); }
    
    void Shoot();
    
    AnimatedSprite mSprite;
protected:
    Vec2D mFowardDirection;
private:
    Vec2D mMovementSpeed;
    Vec2D mVelocity;
    Vec2D mDelta;
    bool mIsMoving;
    
    SpriteSheet *mnoptrSpriteSheet;
};

#endif /* Actor_h */

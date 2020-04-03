//
//  FollowTarget.cpp
//  Shooter
//
//  Created by Guilherme Toda on 03/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "FollowTarget.h"
#include "ShooterGame.h"
#include "Collision.h"

void FollowTarget::Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion, const std::string& explosionSpriteName)
{
    Actor::Init(sprite, animationsPath, initialPos, speed, hasExplosion, explosionSpriteName);
    SetMoving(true);
}

void FollowTarget::Update(uint32_t dt)
{
    if (IsAlive())
    {
        if (Collision::CheckCollisionWithProjectiles(*this))
        {
            KillActor();
            SetAnimation(mExplosionSpriteName, false);
        }
        Vec2D newDirection = mnoptrTarget->GetMiddlePosition() - GetPosition();
        SetMovementDirection(newDirection.Normalize());
        SetVelocity(Vec2D(1.0f, 1.0f));
        
    }
    Actor::Update(dt);
}

void FollowTarget::SetActorToFollow(Actor& actor)
{
    mnoptrTarget = &actor;
}

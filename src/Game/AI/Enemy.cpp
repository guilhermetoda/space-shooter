//
//  Enemy.cpp
//  Shooter
//
//  Created by Guilherme Toda on 01/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "Enemy.h"
#include "ShooterGame.h"
#include "Collision.h"

void Enemy::Init(const SpriteSheet& sprite, const std::string& animationsPath, const Vec2D& initialPos, const Vec2D& speed, bool hasExplosion, const std::string& explosionSpriteName)
{
    Actor::Init(sprite, animationsPath, initialPos, speed, hasExplosion, explosionSpriteName);
    SetMoving(true);
}

void Enemy::Update(uint32_t dt)
{
    if (IsAlive())
    {
        if (Collision::CheckCollisionWithProjectiles(*this))
        {
            KillActor();
            SetAnimation(mExplosionSpriteName, false);
        }
        SetVelocity(Vec2D(1.0f, 1.0f));
    }
    Actor::Update(dt);
}

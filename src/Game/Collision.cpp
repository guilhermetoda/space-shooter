//
//  Collision.cpp
//  Shooter
//
//  Created by Guilherme Toda on 03/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "Collision.h"
#include "Actor.h"
#include "ShooterGame.h"

bool Collision::CheckCollisionWithProjectiles(const Actor& actor)
{
    for (auto& projectile: ShooterGame::mProjectilePool.mPool)
    {
        if (projectile.HasCollided(actor))
        {
            projectile.DestroyProjectile();
            return true;
        }
    }
    return false;
}


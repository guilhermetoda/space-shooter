//
//  ProjectilePool.cpp
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "ProjectilePool.h"

void ProjectilePool::Init()
{
    
}

Projectile& ProjectilePool::AddToPool()
{
    bool foundNotActivePool = false;
    for (int i = 0; i < mPool.size(); ++i)
    {
        if (!mPool[i].IsActive())
        {
            std::cout << "Re-using a pool object";
            foundNotActivePool = true;
            return mPool[i];
        }
    }
    
    Projectile newProjectile;
    mPool.push_back(newProjectile);
    return mPool[mPool.size() - 1];
}

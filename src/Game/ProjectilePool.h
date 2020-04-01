//
//  ProjectilePool.h
//  Shooter
//
//  Created by Guilherme Toda on 31/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef ProjectilePool_h
#define ProjectilePool_h

#include "Projectile.h"
#include <deque>

class ProjectilePool
{
public:
    void Init();
    Projectile& AddToPool();
    inline const size_t Size() const { return mPool.size(); }
    std::deque<Projectile> mPool;
        
};

#endif /* ProjectilePool_h */

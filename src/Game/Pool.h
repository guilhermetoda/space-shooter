//
//  Pool.h
//  Shooter
//
//  Created by Guilherme Toda on 01/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Pool_h
#define Pool_h
#include <deque>
#include <stdint.h>

template <class T>
class Pool
{
public:
    T& AddToPool();
    inline const size_t Size() const { return mPool.size(); }
    std::deque<T> mPool;
};

template <class T>
T& Pool<T>::AddToPool()
{
    bool foundNotActivePool = false;
    for (int i = 0; i < mPool.size(); ++i)
    {
        if (!mPool[i].IsActive())
        {
            foundNotActivePool = true;
            return mPool[i];
        }
    }
    
    T newProjectile;
    mPool.push_back(newProjectile);
    return mPool[mPool.size() - 1];
}


#endif /* Pool_h */

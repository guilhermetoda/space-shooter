//
//  Collision.h
//  Shooter
//
//  Created by Guilherme Toda on 03/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef Collision_h
#define Collision_h

class Actor;

class Collision
{
public:
    static bool CheckCollisionWithProjectiles(const Actor& actor);
};
#endif /* Collision_h */

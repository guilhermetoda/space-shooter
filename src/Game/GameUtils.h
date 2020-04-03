//
//  GameUtils.h
//  Shooter
//
//  Created by Guilherme Toda on 30/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef GameUtils_h
#define GameUtils_h

enum MovementDirections {
    DIRECTION_NONE = 0,
    DIRECTION_DOWN,
    DIRECTION_UP,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

// Direction definitions
static const unsigned char UP_DIR_MASK = 8;
static const unsigned char DOWN_DIR_MASK = 4;
static const unsigned char LEFT_DIR_MASK = 2;
static const unsigned char RIGHT_DIR_MASK = 1;

enum ProjectileOrigin {
    PLAYER = 0,
    ENEMY
};




#endif /* GameUtils_h */

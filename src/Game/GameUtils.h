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

enum ProjectileOrigin {
    PLAYER = 0,
    ENEMY
};

#endif /* GameUtils_h */

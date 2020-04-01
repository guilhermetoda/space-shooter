//
//  ShooterGame.h
//  Shooter
//
//  Created by Guilherme Toda on 27/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef ShooterGame_h
#define ShooterGame_h

#include "Game.h"
#include "SpriteSheet.h"
#include "BMPImage.h"
#include "PlayerShip.h"
#include "GameController.h"
#include "ProjectilePool.h"
#include "Projectile.h"

class ShooterGame : public Game
{
public:
    virtual void Init(GameController& controller);
    virtual void Update(uint32_t dt);
    virtual void Draw(Screen& screen);
    virtual const std::string& GetName() const;
    
    void Shoot(InputState state);
    
    static ProjectilePool mProjectilePool;
    
private:
    void HandleGameControllerState(InputState state, MovementDirections direction);
    
    SpriteSheet mShipSpriteSheet;
    PlayerShip mPlayer;
    
    
    
    // TEMP
    void Shoot();
    Projectile mProjectile;
    BMPImage mBackgroundImage;
    int i = 0;
};

#endif /* ShooterGame_h */

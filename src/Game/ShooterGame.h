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
#include "LevelBackground.h"
#include "PlayerShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Pool.h"
#include "Enemy.h"
#include "FollowTarget.h"


class ShooterGame : public Game
{
public:
    virtual void Init(GameController& controller);
    virtual void Update(uint32_t dt);
    virtual void Draw(Screen& screen);
    virtual const std::string& GetName() const;
    
    void SpawnEnemy();
    
    void Shoot(InputState state);
    
    static Pool<Projectile> mProjectilePool;
    
private:
    void HandleGameControllerState(InputState state, MovementDirections direction);
    
    SpriteSheet mShipSpriteSheet;
    PlayerShip mPlayer;
    
    //Pool<Enemy> mActorsPool;
    Pool<FollowTarget> mActorsPool;
    
    // TEMP
    void Shoot();
    Projectile mProjectile;
    LevelBackground mBackgroundImage;
    float mSpawnTimer;
    const float mEnemySpawnCooldown = 3.0f;
};

#endif /* ShooterGame_h */

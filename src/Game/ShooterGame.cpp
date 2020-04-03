//
//  ShooterGame.cpp
//  Shooter
//
//  Created by Guilherme Toda on 27/03/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "ShooterGame.h"
#include "App.h"
#include "Vec2D.h"
#include "SpriteSheet.h"

#include "Projectile.h"


Pool<Projectile> ShooterGame::mProjectilePool; 

void ShooterGame::Init(GameController& controller)
{
    srand((unsigned)time(0));
    //mBackgroundImage.Load("SpaceBackground");
    mBackgroundImage.Init(App::Singleton().GetBasePath()+"Assets/SpaceClean.bmp");
    mShipSpriteSheet.Load("ShipNGunsSpritesheet");
    
    mPlayer.Init(mShipSpriteSheet, App::Singleton().GetBasePath()+"Assets/ShipNGuns_animations.txt",  Vec2D(100, 600), Vec2D(1.5f,1.5f));
    AARectangle gameBoundary = { Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height() };
    mPlayer.SetBoundary(gameBoundary);
    
    //Controls
    
    ButtonAction leftAction;
    leftAction.key = GameController::LeftKey();
    leftAction.action = [this](uint32_t dt, InputState state)
        {
            HandleGameControllerState(state, DIRECTION_LEFT);
        };
    controller.AddInputActionForKey(leftAction);
    
    ButtonAction rightAction;
    rightAction.key = GameController::RightKey();
    rightAction.action = [this](uint32_t dt, InputState state)
        {
            HandleGameControllerState(state, DIRECTION_RIGHT);
        };
    controller.AddInputActionForKey(rightAction);
    
    ButtonAction downAction;
    downAction.key = GameController::DownKey();
    downAction.action = [this](uint32_t dt, InputState state)
        {
            HandleGameControllerState(state, DIRECTION_DOWN);
        };
    controller.AddInputActionForKey(downAction);
    
    ButtonAction upAction;
    upAction.key = GameController::UpKey();
    upAction.action = [this](uint32_t dt, InputState state)
        {
            HandleGameControllerState(state, DIRECTION_UP);
        };
    controller.AddInputActionForKey(upAction);
    
    ButtonAction shootAction;
    shootAction.key = GameController::ActionKey();
    shootAction.action = [this](uint32_t dt, InputState state)
        {
            Shoot(state);
        };
    controller.AddInputActionForKey(shootAction);
    
    
    
}
void ShooterGame::Update(uint32_t dt)
{
    mBackgroundImage.Update(dt);
    mPlayer.Update(dt);
    for (int i = 0; i < mProjectilePool.Size(); ++i)
    {
        mProjectilePool.mPool[i].Update(dt);
    }
    
    for (int i = 0; i < mActorsPool.Size(); ++i)
    {
        mActorsPool.mPool[i].Update(dt);
    }
    
    if (mSpawnTimer >= mEnemySpawnCooldown)
    {
        SpawnEnemy();
        mSpawnTimer = 0;
    }
    else
    {
        mSpawnTimer += MsToSec(dt);
    }
    
}

void ShooterGame::Draw(Screen& screen)
{
    mBackgroundImage.Draw(screen);
    for (int i = 0; i < mProjectilePool.Size(); ++i)
    {
        mProjectilePool.mPool[i].Draw(screen);
    }
    
    for (int i = 0; i < mActorsPool.Size(); ++i)
    {
        mActorsPool.mPool[i].Draw(screen);
    }
    mPlayer.Draw(screen);
    
    //screen.Draw(mBackgroundSpriteSheet, "space", Vec2D(0,0), Color::White());
}
const std::string& ShooterGame::GetName() const
{
    static std::string title = "Kill the COVID-19";
    return title;
}

void ShooterGame::SpawnEnemy()
{
    int randomXPos = rand() % App::Singleton().Width() + 10;

    //Enemy& enemy = ShooterGame::mActorsPool.AddToPool();
    FollowTarget& enemy = ShooterGame::mActorsPool.AddToPool();
    //FollowTarget enemy;
    Vec2D direction =  mPlayer.GetMiddlePosition() - Vec2D(randomXPos, 10);
    std::cout << direction.Normalize() << std::endl;
    enemy.Init(mShipSpriteSheet, App::Singleton().GetBasePath()+"Assets/ShipNGuns_animations.txt", Vec2D(randomXPos, 10), direction.Normalize(), true, "explosion_red");
    enemy.SetActorToFollow(mPlayer);
    enemy.SetAnimation("covid19", true);
}

void ShooterGame::HandleGameControllerState(InputState state, MovementDirections direction)
{
    if(GameController::IsPressed(state))
    {
        if (direction == DIRECTION_LEFT)
        {
            mPlayer.SetDirection(LEFT_DIR_MASK);
            mPlayer.SetAnimation("move_left", true);
        }
        else if (direction == DIRECTION_RIGHT)
        {
            mPlayer.SetDirection(RIGHT_DIR_MASK);
            mPlayer.SetAnimation("move_right", true);
        }
        else if (direction == DIRECTION_UP)
        {
            mPlayer.SetDirection(UP_DIR_MASK);
            mPlayer.SetVelocity(Vec2D(mPlayer.GetVelocity().GetX(),-1));
        }
        else if (direction == DIRECTION_DOWN)
        {
            mPlayer.SetDirection(DOWN_DIR_MASK);
            mPlayer.SetVelocity(Vec2D(mPlayer.GetVelocity().GetX(),1));
        }
    }
    else if(GameController::IsReleased(state))
    {
        if (direction == DIRECTION_LEFT)
        {
            mPlayer.UnsetDirection(LEFT_DIR_MASK);
        }
        else if (direction == DIRECTION_RIGHT)
        {
            mPlayer.UnsetDirection(RIGHT_DIR_MASK);
        }
        else if (direction == DIRECTION_UP)
        {
            mPlayer.UnsetDirection(UP_DIR_MASK);
        }
        else if (direction == DIRECTION_DOWN) {
            mPlayer.UnsetDirection(DOWN_DIR_MASK);
        }
    }
}

//temp
void ShooterGame::Shoot(InputState state)
{
    if(GameController::IsPressed(state))
    {
        mPlayer.Fire();
    }
    else if(GameController::IsReleased(state))
    {
        mPlayer.StopFire();
    }
}

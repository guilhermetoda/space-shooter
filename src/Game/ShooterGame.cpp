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

void ShooterGame::Init(GameController& controller)
{
    //mBackgroundImage.Load("SpaceBackground");
    mBackgroundImage.LoadImageFromFile(App::Singleton().GetBasePath()+"Assets/SpaceClean.bmp");
    mShipSpriteSheet.Load("ShipNGunsSpritesheet");
    
    mPlayer.Init(mShipSpriteSheet, App::Singleton().GetBasePath()+"Assets/ShipNGuns_animations.txt",  Vec2D(100, 100), Vec2D(1.5f,2.2f));
    
    
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
    
}
void ShooterGame::Update(uint32_t dt)
{
    mPlayer.Update(dt);
}
void ShooterGame::Draw(Screen& screen)
{
    
    Sprite bgSprite;
    bgSprite.width = mBackgroundImage.GetWidth();
    bgSprite.height = mBackgroundImage.GetHeight();
    std::cout << bgSprite.width  << std::endl;
    std::cout << bgSprite.height << std::endl;
    
    screen.Draw(mBackgroundImage, bgSprite, Vec2D(0,i/100), Color::White());
    ++i;
    
    mPlayer.Draw(screen);
    //screen.Draw(mBackgroundSpriteSheet, "space", Vec2D(0,0), Color::White());
}
const std::string& ShooterGame::GetName() const
{
    static std::string title = "Space Shooter... for now";
    return title;
}

void ShooterGame::HandleGameControllerState(InputState state, MovementDirections direction)
{
    if(GameController::IsPressed(state))
    {
        if (direction == DIRECTION_LEFT)
        {
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(-1, mPlayer.GetVelocity().GetY()));
            mPlayer.SetAnimation("move_left", true);
        }
        else if (direction == DIRECTION_RIGHT)
        {
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(1,mPlayer.GetVelocity().GetY()));
            mPlayer.SetAnimation("move_right", true);
        }
        else if (direction == DIRECTION_UP)
        {
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(mPlayer.GetVelocity().GetX(),-1));
        }
        else if (direction == DIRECTION_DOWN)
        {
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(mPlayer.GetVelocity().GetX(),1));
        }
    }
    else if(GameController::IsReleased(state))
    {
        if ((direction == DIRECTION_LEFT) || (direction == DIRECTION_RIGHT))
        {
            mPlayer.SetAnimation("ship_idle", true);
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(0, mPlayer.GetVelocity().GetY()));
        }
        else if ((direction == DIRECTION_UP) || (direction == DIRECTION_DOWN))
        {
            mPlayer.SetMovement(direction, true);
            mPlayer.SetVelocity(Vec2D(mPlayer.GetVelocity().GetX(),0));
        }
    }
}

//
//  LevelBackground.cpp
//  Shooter
//
//  Created by Guilherme Toda on 02/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include "LevelBackground.h"
#include "screen.h"
#include "App.h"
#include "Vec2D.h"

void LevelBackground::Init(const std::string& imageBgPath)
{
    mBackgroundImage.LoadImageFromFile(imageBgPath);
    mInitialPosition = static_cast<int32_t>(App::Singleton().Height()) - static_cast<int32_t>(mBackgroundImage.GetHeight());
    mPosY = mInitialPosition;
    mPosYAux = mInitialPosition - mBackgroundImage.GetWidth();
}

void LevelBackground::Update(uint32_t dt)
{
    /*if (mPosY >= static_cast<int32_t>(App::Singleton().Height()))
    {
        //Resetting
        mPosY = mInitialPosition;
        mPosYAux = mInitialPosition - mBackgroundImage.GetWidth();
    }*/
    //mPosY += MsToSec(dt) / 100;
    //mPosYAux += MsToSec(dt);
    //std::cout << mPosY;
}

void LevelBackground::Draw(Screen& screen)
{
    Sprite bgSprite;
    bgSprite.width = mBackgroundImage.GetWidth();
    bgSprite.height = mBackgroundImage.GetHeight();
    
    if (mPosY >= 0)
    {
        //screen.Draw(mBackgroundImage, bgSprite, Vec2D(0, mPosYAux), Color::White());
    }
    
    screen.Draw(mBackgroundImage, bgSprite, Vec2D(0, mPosY), Color::White());
}

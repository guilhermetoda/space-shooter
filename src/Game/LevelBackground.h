//
//  LevelBackground.h
//  Shooter
//
//  Created by Guilherme Toda on 02/04/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#ifndef LevelBackground_h
#define LevelBackground_h

#include "BMPImage.h"
class Screen;

class LevelBackground
{
public:
    void Init(const std::string& imageBgPath);
    void Update(uint32_t dt);
    void Draw(Screen& screen);
private:
    BMPImage mBackgroundImage;
    int32_t mPosY;
    int32_t mPosYAux;
    int32_t mInitialPosition;
    
};

#endif /* LevelBackground_h */

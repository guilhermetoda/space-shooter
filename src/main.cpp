//
//  main.cpp
//  SDLTest
//
//  Created by Guilherme Toda on 06/02/20.
//  Copyright © 2020 Guilherme Toda. All rights reserved.
//

#include <iostream>
#include "App.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 600;
const int MAGNIFICATION = 1;


int main()
{
    if (App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION))
    {
        App::Singleton().Run();
    }
    
    return 0;
}


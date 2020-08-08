#pragma once
#include <SDL2/SDL.h>

class LevelConfig
{
public:
    static const int mLevelWidth = 640*5;
    static const int mLevelHeight = 480*5;
    static const int mArtifactCount = 150;
    static const int mTime = 120;
    
    static int mCollected;
    static int mElapsed;
    static SDL_Rect mCamera;
};

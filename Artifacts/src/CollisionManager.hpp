#pragma once
#include <SDL2/SDL.h>

class CollisionManager
{
    static CollisionManager* mInstance;
    CollisionManager() {  }
public:
    static CollisionManager* mGetInstance();
    bool mCheckCollision(SDL_Rect a, SDL_Rect b);
};

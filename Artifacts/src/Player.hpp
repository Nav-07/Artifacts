#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Vector2f.hpp"

class Player
{
private:
    int mWidth, mHeight;
    
    SDL_Rect mDestRect;
public:
    int mVelX, mVelY;
    
    Player(Vector2f position, int width, int height);
    void mRender(SDL_Renderer* renderer);
    void mUpdate();
    ~Player();
    
    int& mGetWidth() { return this->mWidth; }
    int& mGetHeight() { return this->mHeight; }
    SDL_Rect& mGetDest() { return this->mDestRect; }
};

#pragma once
#include <SDL2/SDL.h>
#include "Vector2f.hpp"

class Artifact {
private:
    SDL_Rect mDestRect;
    const int mWidth, mHeight;
public:
    Artifact(Vector2f position, int width, int height);
    void mRender(SDL_Renderer* renderer);
    void mUpdate();
    ~Artifact();
    
    SDL_Rect mGetDestRect() { return this->mDestRect; }
};


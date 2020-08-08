#include "Artifact.hpp"
#include "LevelConfig.hpp"

Artifact::Artifact(Vector2f position, int width, int height):
    mWidth(width),
    mHeight(height)
{
    this->mDestRect = {position.x,position.y,this->mWidth,this->mHeight};
}

void Artifact::mUpdate()
{}

void Artifact::mRender(SDL_Renderer* renderer)
{
    SDL_Rect renderRect = { mDestRect.x - LevelConfig::mCamera.x, mDestRect.y - LevelConfig::mCamera.y, mDestRect.w, mDestRect.h };
    SDL_RenderFillRect(renderer, &renderRect);
}

Artifact::~Artifact()
{}

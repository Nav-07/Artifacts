#include "Artifact.hpp"

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
    SDL_RenderFillRect(renderer, &this->mDestRect);
}

Artifact::~Artifact()
{}

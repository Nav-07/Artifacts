#include "Player.hpp"
#include "LevelConfig.hpp"

Player::Player(Vector2f position, int width, int height)
{
    this->mWidth = width;
    this->mHeight = height;
    this->mDestRect.x = position.x;
    this->mDestRect.y = position.y;
    this->mDestRect.w = width;
    this->mDestRect.h = height;
    
    this->mVelX = this->mVelY = 0;
}

void Player::mRender(SDL_Renderer* renderer)
{
    SDL_Rect renderRect = { mDestRect.x - LevelConfig::mCamera.x, mDestRect.y - LevelConfig::mCamera.y, mDestRect.w, mDestRect.h };
    SDL_RenderFillRect(renderer, &renderRect);
}

void Player::mUpdate()
{
    mDestRect.x += mVelX;
    mDestRect.y += mVelY;
    mDestRect.w = mWidth;
    mDestRect.h = mHeight;
}

Player::~Player()
{
}

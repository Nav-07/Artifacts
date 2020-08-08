#include "CollisionManager.hpp"

CollisionManager* CollisionManager::mInstance = nullptr;
CollisionManager* CollisionManager::mGetInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new CollisionManager();
    }
    return mInstance;
}

bool CollisionManager::mCheckCollision(SDL_Rect a, SDL_Rect b)
{
    return (a.x <= b.x + b.w && a.x + a.w >= b.x && a.y <= b.y + b.h && a.y + a.h >= b.y);
}

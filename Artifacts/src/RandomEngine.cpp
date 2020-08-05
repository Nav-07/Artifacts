#include "RandomEngine.hpp"

RandomEngine* RandomEngine::mInstance = nullptr;
RandomEngine* RandomEngine::mGetInstance()
{
    if (mInstance == nullptr)
        mInstance = new RandomEngine();
    return mInstance;
}

float RandomEngine::mGenerateRandomFloat(float min, float max)
{
    
}

int RandomEngine::mGenerateRandoMInt(int min, int max)
{
    
}

void RandomEngine::mDestroy()
{
    
}

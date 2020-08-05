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
    return 0.0f;
}

int RandomEngine::mGenerateRandomInt(int min, int max)
{
    return 0;
}

void RandomEngine::mDestroy()
{
    delete mInstance;
}


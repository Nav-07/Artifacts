#include "RandomEngine.hpp"

RandomEngine* RandomEngine::mInstance = nullptr;
static std::random_device rd;
static std::default_random_engine rng(rd());

RandomEngine* RandomEngine::mGetInstance()
{
    if (mInstance == nullptr)
        mInstance = new RandomEngine();
    return mInstance;
}

float RandomEngine::mGenerateRandomFloat(float min, float max)
{
    std::uniform_int_distribution<float> dist(min, max);
    return dist(rng);
}

int RandomEngine::mGenerateRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void RandomEngine::mDestroy()
{
    delete mInstance;
}


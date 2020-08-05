#pragma once
#include <random>
#include <string>
#include <iostream>

class RandomEngine
{
private:
    static RandomEngine* mInstance;
    RandomEngine() {  }
public:
    static RandomEngine* mGetInstance();
    float mGenerateRandomFloat(float min, float max);
    int mGenerateRandomInt(int min, int max);
    void mDestroy;
};

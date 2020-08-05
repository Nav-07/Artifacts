#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "Artifact.hpp"

class Artifacts
{
private:
    std::vector<Artifact*> mArtifacts;
    const int mArtifactWidth, mArtifactHeight, mScreenWidth, mScreenHeight;
    int mCount;
public:
    Artifacts(int artifactWidth, int artifactHeight, int screenWidth, int screenHeight, int count = 10);
    void mInit();
    void mUpdate();
    void mRender(SDL_Renderer* renderer);
    ~Artifacts();
    
    std::vector<Artifact*>& getArtifacts() { return this->mArtifacts; }
    const int& getArtifactWidth() { return this->mArtifactWidth; }
    const int& getArtifactHeight() { return this->mArtifactHeight; }
};

#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include "Vector2f.hpp"


// Todo: Implementation
class Artifact {
private:
    SDL_Rect mDestRect;
    const int mWidth, mHeight;
public:
    Artifact(Vector2f position, int width, int height);
    void mRender();
    void mUpdate();
    ~Artifact();
};

class Artifacts {
    const int mWindowWidth;
    const int mWindowHeight;
    const int mArtifactWidth;
    const int mArtifactHeight;
    
    std::vector<Vector2f> mPositions;
    std::vector<SDL_Rect> mRects;
    
    Vector2f getPosition(Vector2f prev);
public:
    Artifacts(int windowWidth, int windowHeight);
    void mInit();
    void mRenderStart();
    void mUpdate();
    void mRender(SDL_Renderer* renderer);
    void mRenderEnd();
    ~Artifacts();

    const int& getArtifactWidth() { return this->mArtifactWidth; }
    const int& getArtifactHeight() { return this->mArtifactHeight; }
    std::vector<Vector2f>& getPositions() { return this->mPositions; }
    std::vector<SDL_Rect>& getRects() { return this->mRects; }
};

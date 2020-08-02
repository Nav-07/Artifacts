#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <map>
#include "Vector2f.hpp"

class Artifacts {
    const int mWindowWidth;
    const int mWindowHeight;
    const int mArtifactWidth;
    const int mArtifactHeight;
    
    std::vector<Vector2f> mPositions;
    
    Vector2f getPosition(Vector2f prev);
public:
    Artifacts(int windowWidth, int windowHeight);
    void mInit();
    void mRenderStart();
    void mUpdate();
    void mRender(SDL_Renderer* renderer);
    void mRenderEnd();
    ~Artifacts();
};

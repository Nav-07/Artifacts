#include "Artifacts.hpp"

Artifacts::Artifacts(int artifactWidth, int artifactHeight, int screenWidth, int screenHeight, int count):
    mArtifactWidth(artifactWidth),
    mArtifactHeight(artifactHeight),
    mScreenWidth(screenWidth),
    mScreenHeight(screenHeight),
    mCount(count)
{}

void Artifacts::mInit()
{
    // Initialize Artifacts Locations
    std::vector<Vector2f> locations;
    Vector2f previousLocation;
    
    for (int i = 0; i < mCount; ++i)
    {
        if (i == 0)
        {
            // Generate Random Points
        }
        else
        {
            // Generate Points Based on the Previous Location
        }
    }
    
    // Create the Objects
}

void Artifacts::mUpdate()
{
    // Check for collisions.
}

void Artifacts::mRender(SDL_Renderer *renderer)
{
    // Render them
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (auto& a : mArtifacts)
        a->mRender(renderer);
}

Artifacts::~Artifacts()
{
    // Delete
    for (auto& a : mArtifacts)
        delete a;
}

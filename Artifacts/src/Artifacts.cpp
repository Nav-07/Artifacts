#include "Artifacts.hpp"

Artifacts::Artifacts(int artifactWidth, int artifactHeight, int screenWidth, int screenHeight):
    mArtifactWidth(artifactWidth),
    mArtifactHeight(artifactHeight),
    mScreenWidth(screenWidth),
    mScreenHeight(screenHeight)
{}

void Artifacts::mInit()
{
    // Initialize Artifacts Locations
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
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

Artifacts::~Artifacts()
{
    // Delete
    for (auto& a : mArtifacts)
        delete a;
}

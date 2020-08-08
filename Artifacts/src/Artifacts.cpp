#include "Artifacts.hpp"
#include "RandomEngine.hpp"
#include "CollisionManager.hpp"

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
    Vector2f position = Vector2f();
    
    while (locations.size() < mCount)
    {
        position.x = RandomEngine::mGetInstance()->mGenerateRandomInt(0, mScreenWidth-mArtifactWidth);
        position.y = RandomEngine::mGetInstance()->mGenerateRandomInt(0, mScreenHeight-mArtifactHeight);
        
        bool overlapping = false;
        for (auto& location:locations)
        {
            SDL_Rect a = { location.x, location.y, mArtifactWidth, mArtifactHeight };
            SDL_Rect b = { position.x, position.y, mArtifactWidth, mArtifactHeight };
            if (CollisionManager::mGetInstance()->mCheckCollision(a, b))
            {
                overlapping = true;
                break;
            }
        }
        
        if (!overlapping)
            locations.push_back(position);
    }
    
    // Create the Objects
    for (int i = 0; i < locations.size(); ++i)
    {
        mArtifacts.push_back(new Artifact(locations[i], mArtifactWidth, mArtifactHeight));
    }
}

void Artifacts::mUpdate()
{
    // Check for collisions.
    for (int i = 0; i < mArtifacts.size(); ++i)
        mArtifacts[i]->mUpdate();
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

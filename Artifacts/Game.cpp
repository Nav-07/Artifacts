#include "Game.hpp"
#include "src/Artifact.hpp"

const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
const float fps = 60;
const float frameDelay = 1000 / fps;
Uint32 frameStart, frameTime;

static Artifact* test = nullptr;

Game::Game(int windowWidth, int windowHeight)
{
    this->mWindowWidth = windowWidth;
    this->mWindowHeight = windowHeight;
}

void Game::mInit()
{
    const int playerWidth = 32;
    const int playerHeight = 32;
    Vector2f playerPosition = Vector2f(0, 0);
    mPlayer = new Player(playerPosition, playerWidth, playerHeight);
    
    const int artifactWidth = 16;
    const int artifactHeight = 16;
    const int count = 10;
    mArtifacts = new Artifacts(artifactWidth, artifactHeight, mWindowWidth, mWindowHeight, count);
    mArtifacts->mInit();
    
    test = new Artifact(Vector2f(50, 50), 16, 16);
}

void Game::mRenderStart()
{
    frameStart = SDL_GetTicks();
}

void Game::mUpdate()
{
    mArtifacts->mUpdate();
    mPlayer->mUpdate();
    test->mUpdate();
}

void Game::mRender(SDL_Renderer *renderer)
{
    // Set the Color to White
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    mPlayer->mRender(renderer);
    
    mArtifacts->mRender(renderer);
    test->mRender(renderer);
    
    // Back to Black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Game::mHandleEvents(SDL_Event &e)
{
    const int playerSpeed = 2;
    
    if (isKeyPressed(SDL_SCANCODE_D))
        mPlayer->mVelX += playerSpeed;
    if (isKeyPressed(SDL_SCANCODE_A))
        mPlayer->mVelX += -playerSpeed;
    if (isKeyPressed(SDL_SCANCODE_W))
        mPlayer->mVelY += -playerSpeed;
    if (isKeyPressed(SDL_SCANCODE_S))
        mPlayer->mVelY += playerSpeed;
    
}

void Game::mRenderEnd()
{
    mPlayer->mVelX = mPlayer->mVelY = 0.0f;
    
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime)
        SDL_Delay(frameDelay-frameTime);
}

Game::~Game()
{
    RandomEngine::mGetInstance()->mDestroy();
    
    delete mPlayer;
    delete mArtifacts;
    delete test;
}

bool Game::isKeyPressed(SDL_Scancode key)
{
    if (keyboardState)
    {
        if (keyboardState[key])
        {
            return true;
        }
    }
    return false;
}

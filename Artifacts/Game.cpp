#include "Game.hpp"

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
}

void Game::mUpdate()
{
    mPlayer->mUpdate();
}

void Game::mRender(SDL_Renderer *renderer)
{
    // Set the Color to White
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    mPlayer->mRender(renderer);
    
    // Back to Black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Game::mHandleEvents(SDL_Event &e)
{
}

Game::~Game()
{
    delete mPlayer;
}

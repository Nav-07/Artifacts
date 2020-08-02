#pragma once
#include "src/Player.hpp"
#include "src/Vector2f.hpp"
#include <SDL2/SDL.h>

class Game {
private:
    int mWindowWidth, mWindowHeight;
    Player* mPlayer = nullptr;
public:
    Game(int windowWidth, int windowHeight);
    void mInit();
    void mRenderStart();
    void mRender(SDL_Renderer* renderer);
    void mUpdate();
    void mHandleEvents(SDL_Event& e);
    void mRenderEnd();
    ~Game();
    
    bool isKeyPressed(SDL_Scancode key);
};

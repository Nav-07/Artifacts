#include "src/Player.hpp"
#include <SDL2/SDL.h>

class Game {
private:
    int mWindowWidth, mWindowHeight;
public:
    Game(int windowWidth, int windowHeight);
    void mInit();
    void mRender(SDL_Renderer* renderer);
    void mUpdate();
    void mHandleEvents(SDL_Event& e);
    ~Game();
};

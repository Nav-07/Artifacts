#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "Vector2f.hpp"

class Player
{
private:
    Vector2f mPosition;
    int mWidth, mHeight;
public:
    Player(Vector2f position, int width, int height);
    void mRender();
    void mUpdate();
    ~Player();
    
    Vector2f& getPosition() { return this->mPosition; }
    int& getWidth() { return this->mWidth; }
    int& getHeight() { return this->mHeight; }
};

#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include "Vector2f.hpp"

class TextRenderer
{
    static TextRenderer* mInstance;
    TextRenderer() {}
    
    std::map<std::string, TTF_Font*> mFonts;
public:
    static TextRenderer* mGetInstance();
    void mInit();
    void mLoadFont(std::string id, std::string file, int size);
    void mRenderFont(SDL_Renderer* renderer, std::string id, std::string text, int anchor, SDL_Color color);
    void mDestroy();
};

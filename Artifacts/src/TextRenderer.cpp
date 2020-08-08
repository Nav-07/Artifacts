#include "TextRenderer.hpp"
#include <iostream>

TextRenderer* TextRenderer::mInstance = nullptr;
TextRenderer* TextRenderer::mGetInstance()
{
    if (mInstance == nullptr)
        mInstance = new TextRenderer();
    return mInstance;
}

void TextRenderer::mInit()
{
    TTF_Init();
}

void TextRenderer::mLoadFont(std::string id, std::string file, int size)
{
    TTF_Font* font = TTF_OpenFont(file.c_str(), size);
    if (font == nullptr)
        std::cout << TTF_GetError() << std::endl;
    mFonts.insert({id, font});
}

// anchor == 1: TOP RIGHT
void TextRenderer::mRenderFont(SDL_Renderer *renderer, std::string id, std::string text, int anchor, SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Blended(mFonts[id], text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int width = 0, height = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SDL_Rect rect = { 640-width-10, 5, width, height };
    
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void TextRenderer::mDestroy()
{
    for (auto& font : mFonts)
        TTF_CloseFont(font.second);
}

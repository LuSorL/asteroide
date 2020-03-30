#ifndef TEXTURE_HPP
#define TEXTURE_HPP    
#include "SDL.h"
#include "Border.hpp"
#include <SDL_ttf.h>
#include <iostream>

class Texture {
    public : 
    Texture(SDL_Renderer *renderer, SDL_Color textColor, int score);
    ~Texture();
    void Write();
    void Render();

    protected :
    SDL_Renderer *renderer;
    SDL_Texture* Texture_Surface;
    TTF_Font * gFont;
    float Width;
    float Height;

};

#endif
    
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include "./SDL2/SDL.h"
#include "Border.hpp"
#include "./SDL2/SDL_ttf.h"
#include <iostream>
#include <string>

class Texture {
    public :
    //Texture(SDL_Renderer *renderer, int score);
    Texture();
    ~Texture();
    void clean();
    void Write();
    void Render(SDL_Renderer *renderer);
    bool loadMedia(SDL_Renderer * renderer, int s, int c);
    bool loadFromRenderedText(SDL_Renderer * renderer,int score, int credit);

    protected :
    SDL_Renderer *renderer;
    SDL_Texture* Texture_Surface;
    SDL_Texture* Texture_SurfaceScore;
    SDL_Texture* Texture_SurfaceCred;
    SDL_Texture* Texture_SurfaceCredit;
    TTF_Font * gFont;
    float Width, Height;
    float WidthScore, WidthCred, HeightCred;
    float HeightScore, WidthCredit, HeightCredit;
    SDL_Color textColor;
    SDL_Rect positionScore, position, positionCred, positionCredit;
};

#endif

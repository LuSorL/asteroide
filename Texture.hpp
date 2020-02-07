// #ifndef TEXTURE_HPP
// #define TEXTURE_HPP    
#include "./include/SDL2/SDL.h"

class Texture {
    public : 
    Texture( SDL_Renderer *renderer);

    protected :
    SDL_Renderer *renderer;

};
    
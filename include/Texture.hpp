// #ifndef TEXTURE_HPP
// #define TEXTURE_HPP    
#include "SDL.h"
#include "Border.hpp"

class Texture {
    public : 
    Texture( SDL_Renderer *renderer);

    protected :
    SDL_Renderer *renderer;

};
    
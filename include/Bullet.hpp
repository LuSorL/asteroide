#ifndef BULLET_HPP
#define BULLET_HPP
#include "./SDL2/SDL.h"
#include "Border.hpp"
#include <iostream>
#include "./SDL2/SDL_image.h"
#include <vector>

class Bullet {
    public :
    ~Bullet();
    Bullet( SDL_Renderer *renderer ,const char* path, float vaisseauX, float vaisseauY);
    SDL_Rect* Position();
    SDL_Texture* Texture();
    bool Collision(SDL_Rect* positionAst);
    void clean();


    protected :
    SDL_Renderer *renderer;
    SDL_Texture* Texture_bullet;
    SDL_Rect dest_bullet;
    int x;
    int y;
};

#endif

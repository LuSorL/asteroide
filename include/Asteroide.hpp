#ifndef ASTEROIDE_HPP
#define ASTEROIDE_HPP
#include <vector>
#include "./SDL2/SDL.h"
#include "Border.hpp"
#include "fonction.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;


class Asteroide {
    public :
    Asteroide(SDL_Renderer *renderer, const char* path, float posX, float posY);
    ~Asteroide();
    bool IsDead();
    void UpdateAsteroide();
    bool Collision(SDL_Rect* positionRocket);
    float GetSize();
    void Render();
    void clean();
    SDL_Rect* Position();

    protected :
    SDL_Rect speed;
    SDL_Renderer *renderer;
    SDL_Texture *Texture_ast;
    SDL_Rect dest_ast;
    bool dead;
    float size;
};
#endif

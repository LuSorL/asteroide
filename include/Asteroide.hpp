// #ifndef ASTEROIDE_HPP  
// #define ASTEROIDE_HPP
#include <vector>
#include "SDL.h"
#include "Border.hpp"
#include <cstdlib> 
#include <iostream>

using namespace std;


class Asteroide {
    public :
    Asteroide(SDL_Renderer *renderer, const char* path);
    ~Asteroide();
    bool IsDead();
    float Random(float x,float y);
    void UpdateAsteroide();
    void RandomSprite();
    bool Collision(SDL_Rect* positionRocket);
    float GetSize();
    void Render();
    void Render2(void);
    void clean();
    SDL_Rect* Position();

    protected : //private ?
    SDL_Rect speed;
    SDL_Renderer *renderer;
    SDL_Texture *Texture_ast;
    Uint32 format;
    int access;
    SDL_Rect src;
    SDL_Rect dest_ast;
    int L;
    int H;
    int result;
    char *path;
    SDL_Rect Box;
    SDL_Rect collisionRect;
    float angularSpeed; //vitesse de rotation
    float angle;
    bool dead; 
    float size;
    int x, y;
};
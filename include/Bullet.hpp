#ifndef BULLET_HPP  
#define BULLET_HPP
#include "SDL.h"
#include "Border.hpp"
#include <iostream>
#include "SDL_image.h"
#include <vector>

class Bullet {
    public : 
    ~Bullet();
    Bullet( SDL_Renderer *renderer ,const char* path, float vaisseauX, float vaisseauY, float angleV);
    void handleEvent(SDL_Event &e, float angle);
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
    int quit;
    Uint32 format;
    int a;
    int L;
    int H;
    int speed;
    float angle;
    float angularSpeed;
    int createdNow;  // instant t de création de la balle


};

#endif
#ifndef BULLET_HPP  
#define BULLET_HPP
#include "SDL.h"
#include "Border.hpp"
#include <iostream>
#include "SDL_image.h"

class Bullet {
    public : 
    ~Bullet();
    Bullet( SDL_Renderer *renderer ,const char* path, float vaisseauX, float vaisseauY, float angleV);
    void Render2(float posX, float posY);
    void clean();
    bool Remove();
    void handleEvent(SDL_Event &e, float angle);
    void move(float angle);
    SDL_Rect* Position();
    //void Draw(float x, float y, float angle);

    protected : 
    SDL_Renderer *renderer;
    SDL_Texture* Texture_bullet;
    SDL_Rect Box;
    SDL_Rect dest_bullet;
    int x;
    int y;
    int Vx,Vy;
    int quit;
    Uint32 format;
    int a;
    int L;
    int H;
    int speed;
    float angle;
    float angularSpeed;
    int apparitionTime ; // durée d'apparition en ms 
    int createdNow;  // instant t de création de la balle

};

#endif
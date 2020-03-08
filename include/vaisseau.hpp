#ifndef VAISSEAU_HPP  
#define VAISSEAU_HPP
#include "SDL.h"
#include "./SDL2_rotozoom.h"
#include "Border.hpp"
#include <iostream>
#include "Bullet.hpp"
#include <vector>

#define NB_MIS 1000

const float ANGULARSPEED = 15;
const int MAX_BULLETS = 100;
const float SPEED = 30;

class vaisseau {
    public : 
    /*VAISSEAU*/
    vaisseau(SDL_Renderer *renderer, const char* path);
    ~vaisseau();
    void Reset(); //Reset Game
    void Rotate(int direction); // rotation du vaisseauc
    void handleEvent(SDL_Event &e,SDL_Texture* texture, SDL_Rect &dest);
    void Render2(void);
    void moveUp(float angle);
    float getAngle();
    SDL_Rect* Position();
    void UpdateCredit(int i);
    void UpdateScore();
    bool IsDead();
    void clean();

    /* BULLET */
    void Update_bullet();
    void Render_bullet();
    int MissileSize();
    Bullet* Missile(int i);
    Bullet* Fire();

    protected :
    int vX; // vitesse du vaisseau
    int vY;
    float xN;
    float yN;
    int x, y; // position du vaisseau
    int width;
    int height;
    char *path;
    float angle; 
    Uint32 format;
    int a;
    int result;
    int quit;
    SDL_Rect positionRocket;
    SDL_Point center;
    SDL_Rect src;
    SDL_Renderer *renderer;
    SDL_Rect RenderRect;
    SDL_Texture *Texture_rocket;

    SDL_Texture* texture;
    Bullet *bullet;
    Bullet *newBullet;
    float accelerationFactor;
    int credit; // Vie
    int bulletUsed; 
    std::vector<Bullet*> missile;
    int score;

};

#endif
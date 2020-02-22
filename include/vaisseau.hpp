#ifndef VAISSEAU_HPP  
#define VAISSEAU_HPP
#include "SDL.h"
#include "./SDL2_rotozoom.h"
#include "Border.hpp"
#include <iostream>
//#include "Bullet.hpp"

class vaisseau {
    public : 
    vaisseau(SDL_Renderer *renderer, const char* path);
    ~vaisseau();
    void Reset(); //Reset Game
    void Rotate(int direction); // rotation du vaisseau
    void clean();
    void ResetBulletCoolDown();
    void handleEvent(SDL_Event &e,SDL_Texture* texture, SDL_Rect &dest);
    void Acceleration();
    //Bullet* Fire();
    void EndFire();
    void Render();
    void Render2(void);
    void moveUp(float angle);
    void moveDown(float angle);
    bool IsDead();
    void UpdateCredit(int i);
    SDL_Rect* Position();
    
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
    SDL_Rect Box;
    SDL_Rect RenderRect;
    SDL_Rect mainColliderRect;
    SDL_Rect leftColliderRect;
    SDL_Rect rightColliderRect;
    SDL_Texture *Texture_rocket;
    SDL_Texture* texture;
    float accelerationFactor;
    int credit; // Vie
    int bulletCoolDown;
    int lastBulletTime ; 
    int maxBullet;
    int bulletUsed; 

};

#endif
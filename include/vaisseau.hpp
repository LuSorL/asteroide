#ifndef VAISSEAU_HPP
#define VAISSEAU_HPP
#include "./SDL2/SDL.h"
#include "./SDL2/SDL2_rotozoom.h"
#include "Border.hpp"
#include "Bullet.hpp"
#include <iostream>
#include <vector>
#include<cstdio>

#define NB_MIS 1000
#define CREDIT 100
const float ANGULARSPEED = 20;
const int MAX_BULLETS = 100;
const float SPEED = 50;
const float SPEED_MISSILE = 20;

class vaisseau {
    public :
    /*VAISSEAU*/
    vaisseau(SDL_Renderer *renderer, const char* path);
    ~vaisseau();
    void Rotate(int direction); 
    void handleEvent();
    void Render(void);
    void move(float angle);
    float getAngle();
    SDL_Rect* Position();
    void UpdateCredit(int i);
    void UpdateScore(int i);
    bool IsDead();
    void clean();
    int Score();
    int Credit();

    /* BULLET */
    void Update_bullet();
    void Render_bullet();
    int MissileSize();
    Bullet* Missile(int i);
    Bullet* Fire();
    void Erase(int j);

    protected :
    int x, y; // position du vaisseau
    float angle; // angle du vaisseau
    int credit; // Vies
    int score;
    SDL_Rect positionRocket;
    SDL_Point center;
    SDL_Rect src;
    SDL_Renderer *renderer;
    SDL_Rect RenderRect;
    SDL_Texture *Texture_rocket;

    /* Objets Bullet */
    SDL_Texture* texture;
    int bulletUsed;
    std::vector<Bullet*> missile; // Vecteur contenant nos missiles

};

#endif

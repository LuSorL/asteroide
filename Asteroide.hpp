// #ifndef ASTEROIDE_HPP  
// #define ASTEROIDE_HPP
#include <vector>
#include "./include/SDL2/SDL.h"
#include <cstdlib> 
#include <iostream>

using namespace std;


class Asteroide {
    public :
    Asteroide(SDL_Renderer *renderer, const char* path);
    ~Asteroide();
    bool IsDead();
    float Random(float x,float y);
    void InitAsteroide();
    void UpdateAsteroide();
    void RandomSprite();
    bool Collision();
    float GetSize();
    void Render();

    protected : //private ?
    std::vector<float> position;
    std::vector<float> speed;
    SDL_Renderer *renderer;
    SDL_Texture *Texture_ast;
    char* path;
    SDL_Rect Box;
    SDL_Rect collisionRect;
    float angularSpeed; //vitesse de rotation
    float angle;
    bool dead; 
    float size;
};
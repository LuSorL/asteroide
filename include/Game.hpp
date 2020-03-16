#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include <iostream>
#include "Border.hpp"
#include "Texture.hpp"
#include "Bullet.hpp"
#include "vaisseau.hpp"
#include "Asteroide.hpp"
#include <vector> 
#include <cstdlib>

#define NB_AST 8


using namespace std;

class Game{
    public : 
    Game();
    ~Game();
    int initialization();
    void newGame();
    void clean();
    void run();
    void handleEvent(SDL_Event e);
    void CreateNewAsteroide();
    float Random(float x, float y);

    private : 
    SDL_Renderer* renderer;
	SDL_Window* window;
    SDL_Texture *texture;
    SDL_Event e;
    SDL_Rect dest;
    Uint32 format;
    int access;
    int largeur;
    int hauteur;
    vaisseau* rocket;
    std::vector<Asteroide*> asteroides;
    Asteroide* asteroide;
    Asteroide* mid_ast_1;
    Asteroide* mid_ast_2;
    Asteroide* mini_ast_1;
    Asteroide* mini_ast_2;
    int quit;
    float bigSize;
    float normalSize;
};

#endif
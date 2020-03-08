#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include <iostream>
#include "Border.hpp"
#include "Texture.hpp"
#include "Bullet.hpp"
#include "vaisseau.hpp"
#include "Asteroide.hpp"

#define NB_AST 10


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
    Asteroide* asteroide[NB_AST];
};

#endif
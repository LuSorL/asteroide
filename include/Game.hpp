#ifndef GAME_HPP
#define GAME_HPP

#include "./SDL2/SDL.h"
#include "./SDL2/SDL_ttf.h"
#include <iostream>
#include "Border.hpp"
#include "Texture.hpp"
#include "Bullet.hpp"
#include "vaisseau.hpp"
#include "Asteroide.hpp"
#include "fonction.hpp"
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
    void CreateNewAsteroide();

    private :
    SDL_Renderer* renderer;
	  SDL_Window* window;
    SDL_Texture *texture;
    SDL_Event e;
    SDL_Rect dest;
    vaisseau* rocket;
    std::vector<Asteroide*> asteroides;
    Asteroide* asteroide;
    Texture* police;
    int quit;
    float bigSize; // Pour les astéroides
    float normalSize;
};

#endif

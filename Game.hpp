#include "./include/SDL2/SDL.h"
#include <iostream>

#include "Texture.hpp"
#include "Bullet.hpp"
#include "vaisseau.hpp"
#include "Asteroide.hpp"

using namespace std;

class Game{
    public : 
    Game();
    ~Game();
    int initialization();
    void newGame();
    void clean();
    void Update();
    void handleEvent();

    private : 
    SDL_Renderer* renderer;
	SDL_Window* window;
    SDL_Texture *texture;
    SDL_Event e;
    vaisseau *vaisseau;
    Asteroide *Asteroide;
};
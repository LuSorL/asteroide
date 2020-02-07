#include "Game.hpp"

Game::Game(): window(0), renderer(0) {
    // constructeur 
}

Game::~Game(){
    window = NULL;
    renderer = NULL;
}

int Game::initialization(){
    
    SDL_Surface *imageDeFond;
    SDL_Texture *texture;
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        cout << " init fail" << endl;
        return EXIT_FAILURE;
    }

    int width = 800;
    int height = 900;

    window = SDL_CreateWindow(
        "Game",                            // window title
        SDL_WINDOWPOS_UNDEFINED,                                // initial x position
        SDL_WINDOWPOS_UNDEFINED,                                  // initial y position
        width,                               // width, in pixels
        height,                               // height, in pixels
        SDL_WINDOW_SHOWN                  
    );

    if (window == NULL) {
        cout << "Could not open Window: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){   
        cout << "Could not open Renderer: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    imageDeFond = SDL_LoadBMP("fond.bmp");

    if ( imageDeFond == NULL){
        std::cout << " Problème imageDeFond" << SDL_GetError() << std::endl;
    }
    else{
        texture = SDL_CreateTextureFromSurface(renderer, imageDeFond);
        if( texture == NULL){
            std::cout << " Problème Texture" << SDL_GetError() << std::endl;
        }
    }
    SDL_FreeSurface(imageDeFond);

    return EXIT_SUCCESS;
}

void Game::newGame(){

}

void Game::Update(){
    delete vaisseau;
    //delete texture;
    vaisseau = new class vaisseau( renderer, "vaisseau.bmp");
    //texture = new Texture( renderer );
}

void Game::handleEvent(){

}

void Game::clean(){
    // Close and destroy the window, the renderer and the Texture, rocket
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyTexture(texture);
    // Clean up
    SDL_Quit();
}
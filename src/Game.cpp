#include "../include/Game.hpp"



Game::Game(){

}

Game::~Game(){
    window = NULL;
    renderer = NULL;
}

int Game::initialization(){
    
    SDL_Surface *imageDeFond;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        cout << " init fail" << endl;
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(
        "Game",                            // window title
        SDL_WINDOWPOS_UNDEFINED,                                // initial x position
        SDL_WINDOWPOS_UNDEFINED,                                  // initial y position
        WIDTH_SCREEN,                               // width, in pixels
        HEIGHT_SCREEN,                               // height, in pixels
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

    imageDeFond = SDL_LoadBMP("./src/fond.bmp");

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

    SDL_QueryTexture(texture,&format, &access, &largeur, &hauteur);

    dest.x = WIDTH_SCREEN/2 - largeur/2;
    dest.y = HEIGHT_SCREEN/2 - hauteur/2;
    dest.w = largeur;
    dest.h = hauteur;

    Game::newGame();
    
    return EXIT_SUCCESS;
}

void Game::run(){
    int quit = 0;
    
    while( !quit ){

        // déplacement astéroide & tests collisions
        for (int i = 0; i < NB_AST; i++)
        {
            asteroide[i]->UpdateAsteroide();
            
            if (asteroide[i]->Collision(rocket->Position()))
            {
                rocket->UpdateCredit(-1);
            }
            if (rocket->IsDead())
            {
                quit = 1;
            }

            for ( int j = 0; j < rocket->MissileSize() ; j++){
                if ( rocket->Missile(j)->Collision( asteroide[i]->Position() )){
                    rocket->UpdateScore(); // à modifier fonctionne pas correctement
                    asteroide[i]->clean();
                    rocket->Missile(j)->clean();
                }
            }
        }


        while(SDL_PollEvent(&e) ){
            if( e.type == SDL_QUIT){
                quit = 1;
            }
            rocket->handleEvent(e,texture,dest);
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture,NULL,&dest);

        rocket->Render2();
        rocket->Update_bullet();
        rocket->Render_bullet();
        for (int i = 0; i < NB_AST; i++)
        {
            asteroide[i]->Render2();
        }

        SDL_RenderPresent(renderer);
    }
    
}

void Game::newGame(){
    for (int i=0; i< NB_AST; i++){
        asteroide[i] = new Asteroide(renderer, "./src/asteroide1.bmp");
    }
    rocket = new vaisseau(renderer, "./src/vaisseauR.bmp");

}

void Game::handleEvent(SDL_Event e){
    rocket->handleEvent(e,texture,dest);
}

void Game::clean(){
    // Close and destroy the window, the renderer and the Texture
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyTexture(texture);
    rocket->clean();
    for (int i = 0; i < NB_AST; i++)
    {
        asteroide[i]->clean();
    }
    // Clean up
    SDL_Quit();
}
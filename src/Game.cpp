#include "../include/Game.hpp"



Game::Game(){}

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
        "Game",                         
        SDL_WINDOWPOS_UNDEFINED,           
        SDL_WINDOWPOS_UNDEFINED,                                 
        WIDTH_SCREEN,                               
        HEIGHT_SCREEN,                              
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

    quit = 0 ;

    while( !quit ){

        // déplacement astéroide & tests collisions
        for (int i = 0; i < asteroides.size(); i++)
        {
            asteroides[i]->UpdateAsteroide();
            
            if (asteroides[i]->Collision(rocket->Position()))
            {
                rocket->UpdateCredit(-1);
            }
            if (rocket->IsDead())
            {
                quit = 1;
            }

            for ( int j = 0; j < rocket->MissileSize() ; j++){
                if ( rocket->Missile(j)->Collision( asteroides[i]->Position() )){
                    std::cout << " missile " << j << std::endl;
                    std::cout << "size missile " << rocket->MissileSize() << std::endl;
                    rocket->Missile(j)->clean();
                    rocket->Erase(j);

                    rocket->UpdateScore(); 

                    if ( asteroides[i]->GetSize() >= bigSize ){ // Si l'asteroide détruite est la pus grande
                        // on fait apparaître 2 mid_ast à la même position que l'astéroide précédente
                        std::cout << " premiere condition " << j << std::endl;
                        mid_ast_1 = new Asteroide(renderer, "./src/asteroide1.bmp", asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        mid_ast_2 = new Asteroide(renderer, "./src/asteroide1.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        asteroides[i]->clean();
                        asteroides.push_back(mid_ast_1);
                        asteroides.push_back(mid_ast_2);

                    }
                    else if ( (asteroides[i]->GetSize() >= normalSize) && (asteroides[i]->GetSize()< bigSize) ){
                        std::cout << " deuxieme if " << j << std::endl;
                        mini_ast_1 = new Asteroide(renderer, "./src/mini.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->x);
                        mini_ast_2 = new Asteroide(renderer, "./src/mini.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        asteroides[i]->clean();
                        asteroides.push_back(mini_ast_1);
                        asteroides.push_back(mini_ast_2);
                    }
                    else{
                        std::cout << " destruction mini" << j << std::endl;
                        asteroides[i]->clean();
                    }
                    asteroides.erase(asteroides.begin() + i);
                    std::cout << " nombre d'astéroides " << asteroides.size() << std::endl;
                }
            }

            if ( (asteroides.size() < NB_AST ) ){
                CreateNewAsteroide();
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

        for (int i = 0; i < asteroides.size(); i++)
        {
            asteroides[i]->Render();
        }

        SDL_RenderPresent(renderer);
    }
    
}

void Game::newGame(){

    for (int i = 0 ; i< NB_AST; i++){
        CreateNewAsteroide();
    }

    rocket = new vaisseau(renderer, "./src/vaisseauR.bmp");

}

void Game::CreateNewAsteroide(){
    
    /* Cette fonction créée une asteroide pouvant avoir 3 tailles différentes */

    int r = rand() % 3 + 1;

    float posX = Random(0, WIDTH_SCREEN);
    float posY = Random(0, HEIGHT_SCREEN);

    switch(r){
        case 1 :
        asteroide = new Asteroide(renderer, "./src/asteroide1.bmp", posX, posY);
        normalSize = asteroide->GetSize();
        break;

        case 2 : 
        asteroide = new Asteroide(renderer, "./src/mini.bmp", posX, posY);
        break; 

        case 3 :
        asteroide = new Asteroide(renderer, "./src/big.bmp", posX, posY);
        bigSize = asteroide->GetSize();
        break;
    }

    asteroides.push_back(asteroide);

}


void Game::handleEvent(SDL_Event e){

    rocket->handleEvent(e,texture,dest);

}

float Game::Random(float x, float y){
    // fonction rendant un chiffre entre x et y
    if (x < y ){
        return ((float)rand() / (float)(RAND_MAX)) * (y-x) + x;
    }
    else{
        return ((float)rand() / (float)(RAND_MAX)) * (x-y) + y;
    }
}

void Game::clean(){

    // Close and destroy the window, the renderer and the Texture
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyTexture(texture);

    rocket->clean();

    for (int i = 0; i < asteroides.size() ; i++)
    {
        asteroides[i]->clean();
    }
    // Clean up
    SDL_Quit();

}
#include "../include/Game.hpp"



Game::Game(){}

Game::~Game(){
    window = NULL;
    renderer = NULL;
}

int Game::initialization(){
    Uint32 format;
    int access;
    int largeur;
    int hauteur;
    /* Initialisation du jeu */
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
        return EXIT_FAILURE;
    }
    else{
        texture = SDL_CreateTextureFromSurface(renderer, imageDeFond);
        if( texture == NULL){
            std::cout << " Problème Texture" << SDL_GetError() << std::endl;
            return EXIT_FAILURE;
        }
    }
    SDL_FreeSurface(imageDeFond);

    if (TTF_Init() == -1){
        std::cout << " Problème initialisation TTF " << TTF_GetError() << std::endl;
        return EXIT_FAILURE;
    }

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
    Asteroide* mid_ast_1;
    Asteroide* mid_ast_2;
    Asteroide* mini_ast_1;
    Asteroide* mini_ast_2;

    // Tant qu'on ne quitte pas
    while( !quit ){

        // déplacement astéroide aléatoire & tests collisions
        for (size_t i = 0; i < asteroides.size(); i++)
        {
            // Mise à jour de la position de l'astéroide
            asteroides[i]->UpdateAsteroide();

            // Si on a collision entre la rocket et l'astéroide
            if (asteroides[i]->Collision(rocket->Position()))
            {
                if ( asteroides[i]->GetSize() >= bigSize ) {
                    // Enlever 3 vies à rocket si l'astéroide est de taille maximale
                    rocket->UpdateCredit(-3);
                }
                else if ( (asteroides[i]->GetSize() >= normalSize) && (asteroides[i]->GetSize()< bigSize) ){
                    // Enelver 2 vies à rocket si l'astéroide est de taille moyenne
                    rocket->UpdateCredit(-2);
                }
                else {
                    // Sinon lui retirer une vie
                    rocket->UpdateCredit(-1);
                }

            }
            // Si rocket est morte on quitte
            if (rocket->IsDead())
            {
                quit = 1;
            }

            // Missile
            // Pour tous nos missiles
            for ( int j = 0; j < rocket->MissileSize() ; j++){
                // On regarde si il y a collisions avec l'astéroide
                // Si oui on l'efface et on met à jour le score
                if ( rocket->Missile(j)->Collision( asteroides[i]->Position() )){
                    rocket->Missile(j)->clean();
                    rocket->Erase(j);

                    //rocket->UpdateScore();

                    if ( asteroides[i]->GetSize() >= bigSize ){ // Si l'asteroide détruite est la pus grande
                        // on fait apparaître 2 mid_ast à la même position que l'astéroide précédente

                        /* 3 points en plus pour une astéroide de taille maximale*/
                        rocket->UpdateScore(3);

                        /* Apparition de 2 mid astéroides */
                        mid_ast_1 = new Asteroide(renderer, "./src/asteroide1.bmp", asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        mid_ast_2 = new Asteroide(renderer, "./src/asteroide1.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        asteroides[i]->clean();
                        asteroides.push_back(mid_ast_1);
                        asteroides.push_back(mid_ast_2);

                    }
                    else if ( (asteroides[i]->GetSize() >= normalSize) && (asteroides[i]->GetSize()< bigSize) ){
                        /* 2 points en plus pour une astéroide de taille moyenne */
                        rocket->UpdateScore(2);

                        /* Quand l'astéroide est de taille moyenne on l'a sous divise en deux petites astéroides */
                        mini_ast_1 = new Asteroide(renderer, "./src/mini.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->x);
                        mini_ast_2 = new Asteroide(renderer, "./src/mini.bmp",asteroides[i]->Position()->x, asteroides[i]->Position()->y);
                        asteroides[i]->clean();
                        asteroides.push_back(mini_ast_1);
                        asteroides.push_back(mini_ast_2);
                    }
                    else{
                        /* 1 point en plus pour une astéroide de taille minimale */
                        rocket->UpdateScore(1);

                        /*Quand l'astéroide a la taille minimale on la supprime*/
                        asteroides[i]->clean();
                    }
                    asteroides.erase(asteroides.begin() + i);
                }
            }

            // Permet d'avoir un nombre d'astéroides minimum sur l'écran
            if ( (asteroides.size() < NB_AST ) ){
                CreateNewAsteroide();
            }
        }

        // Il faut regarder la fonction handleEvent de rocket pour les évènements
        while(SDL_PollEvent(&e) ){
            if( e.type == SDL_QUIT){
                quit = 1;
            }
            rocket->handleEvent();
        }

        // Affichage
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture,NULL,&dest);

        rocket->Render();
        rocket->Update_bullet();
        rocket->Render_bullet();

        police->loadFromRenderedText( renderer, rocket->Score(), rocket->Credit());
        police->Render(renderer);

        for (size_t i = 0; i < asteroides.size(); i++)
        {
            asteroides[i]->Render();
        }

        SDL_RenderPresent(renderer);
    }

}

void Game::newGame(){

    // Création de nos objets

    for (int i = 0 ; i< NB_AST; i++){

        CreateNewAsteroide();

    }

    rocket = new vaisseau(renderer, "./src/vaisseauR.bmp");

    police = new Texture();

    if ( !police->loadMedia(renderer, rocket->Score(), rocket->Credit())){
        std::cout << " police loadMedia " << std::endl;
    }

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


void Game::clean(){

    // Close and destroy the window, the renderer and the Texture
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);

    // Clean nos objets
    rocket->clean();
    police->clean();
    for (size_t i = 0; i < asteroides.size() ; i++)
    {
        asteroides[i]->clean();
    }
    // Clean up
    SDL_Quit();
    TTF_Quit();

}

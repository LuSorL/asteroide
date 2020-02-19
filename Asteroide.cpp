#include "../include/Asteroide.hpp"

const float SIZE_AST = 70; // a changer

Asteroide::Asteroide(SDL_Renderer *renderer, const char* path) 
{
    SDL_Point center = { 300, 300};
    SDL_Texture *Texture_ast;
    SDL_Surface *asteroide;
    asteroide = SDL_LoadBMP(path);
    if (asteroide == NULL ){
        std::cout << "Problem surface asteroide" << SDL_GetError() << std::endl;

    }
    else {
        SDL_SetColorKey(asteroide, SDL_TRUE, SDL_MapRGB(asteroide->format, 255, 255, 255));
        Texture_ast = SDL_CreateTextureFromSurface(renderer, asteroide);
        if (Texture_ast == NULL ){
            std::cout << "Problem texture asteroide" << SDL_GetError() << std::endl;
        }
        else {
            // Box va contenir asteroide pour détecter les collisions par la suite
            Box.w = asteroide->w;
            Box.h = asteroide->h;
        }
    }
    SDL_FreeSurface(asteroide);

    SDL_QueryTexture(Texture_ast,&format, &access, &L, &H);
    SDL_Rect src = {0,0, H, L};
    SDL_Rect dest_ast = { 900/2-L/2 , 900/2-H/2, H, L};
    result = SDL_RenderCopyEx(renderer, Texture_ast, &src , &dest_ast, angle, &center, SDL_FLIP_NONE);

    if ( result != 0 ){
        cout << SDL_GetError() << endl;
    }
    SDL_RenderPresent(renderer);
    position[0] = Asteroide::Random(0,800);
    position[1] = Asteroide::Random(0,900);

    //Box.w = SIZE_AST;
    //Box.h = Box.w;
    //Box.x = position[0];
    //Box.y = position[1] - Box.h

    speed[0] = Asteroide::Random(0,100);
    speed[1] = Asteroide::Random(0,100);

    angle = Asteroide::Random(-2.0, 2.0); // A MODIFIER
    angularSpeed = Asteroide::Random(-0.1,0.1); 

    dead = false ; 
    //size ; // = ?
}

Asteroide::~Asteroide(){
    SDL_DestroyTexture(Texture_ast);
}

bool Asteroide::IsDead(){
    return dead; 
}

void Asteroide::InitAsteroide(){
    // début du jeu
    speed[0] = Asteroide::Random(-0.1,200.0);
    speed[1] = Asteroide::Random(-0.1,200.0);
    angularSpeed = Asteroide::Random(-0.1,0.1); 
    dead = false;
}

void Asteroide::UpdateAsteroide(){
    // pendant le jeu
}

float Asteroide::GetSize(){
    return size;
}

float Asteroide::Random(float x, float y){
    // fonction rendant un chiffre entre x et y
    if (x < y ){
        return ((float)rand() / (float)(RAND_MAX)) * (y-x) + x;
    }
    else{
        return ((float)rand() / (float)(RAND_MAX)) * (x-y) + y;
    }
}

bool Asteroide::Collision(){
    // SDL_HasIntersection(collisionRect, ? )

    return true;
    
}


void Asteroide::RandomSprite(){
    /*
    int sprite = 1 + rand() % 2;
    switch (sprite){
        case 1 : 
        path = " asteroide1.bmp";
        break;
        case 2 : 
        path = " asteroide2.bmp";
        break;
        default : 
        path = " asteroide3.bmp";
        break;
    }
    */
}

void Asteroide::Render(){
    // A MODIFIER
        
    collisionRect.x = Box.x ; // + qqch ?
    collisionRect.y = Box.y ; // +qqch ?
    collisionRect.h = Box.h ;
    collisionRect.w =  Box.w; 

    SDL_Point center; // valeur ?
    int A, L,H; // Où les déclarer ?
    Uint32 format1; 
    SDL_QueryTexture(Texture_ast,&format1, &A, &L, &H);
    SDL_Rect src = {0,0, H, L}; // valeur à modifier
    SDL_Rect dest_ast = { 800/2-L/2 , 900/2-H/2, H, L};
    int result = SDL_RenderCopyEx(renderer, Texture_ast, &src , &Box, angle, &center, SDL_FLIP_NONE);

    if ( result != 0 ){
        std::cout << SDL_GetError() << std::endl;
    }


}
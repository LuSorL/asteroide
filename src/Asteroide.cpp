#include "../include/Asteroide.hpp"

const float SIZE_AST = 70; // a changer

Asteroide::Asteroide(SDL_Renderer *renderer, const char* path) 
{
    SDL_Surface *asteroide;
    this->renderer = renderer;
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

    x = Random(0, WIDTH_SCREEN) ;
	y = Random(0, HEIGHT_SCREEN) ;  

	angle = 0;

    
    SDL_QueryTexture(Texture_ast,&format, &access, &L, &H);

    src.x = 0;
	src.y = 0;
	src.w = L; 
	src.h = H;


    dest_ast.x = x;
    dest_ast.y = y;
    dest_ast.w = L;
    dest_ast.h = H;

    do {
        speed.x = Random(-2, 2);
        speed.y = Random(-2, 2);
    }while (speed.x == 0 && speed.y == 0);
    
    Box.w = SIZE_AST;
    Box.h = Box.w;
    Box.x = 1;
    Box.y = 1;

    dead = false ; 
}

Asteroide::~Asteroide(){
    SDL_DestroyTexture(Texture_ast);
}

bool Asteroide::IsDead(){
    return dead; 
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

void Asteroide::UpdateAsteroide(){
    // pendant le jeu
    dest_ast.x += speed.x;
    dest_ast.y += speed.y;

    if (dest_ast.x <= 0)
    {
        dest_ast.x = dest_ast.x + WIDTH_SCREEN;
    }
    if (dest_ast.x >= WIDTH_SCREEN)
    {
        dest_ast.x = dest_ast.x - WIDTH_SCREEN;
    }
    if (dest_ast.y >= HEIGHT_SCREEN)
    {
        dest_ast.y = dest_ast.y - HEIGHT_SCREEN;
    }
    if (dest_ast.y <= 0)
    {
        dest_ast.y = dest_ast.y + HEIGHT_SCREEN;
    }
}


bool Asteroide::Collision(SDL_Rect* positionRocket){

    bool Bool = SDL_HasIntersection(&dest_ast, positionRocket);

    if(Bool){
        if (speed.x > 0){
            dest_ast.y = HEIGHT_SCREEN/2;
            dest_ast.x = 0;
        }
        else {
            dest_ast.y = HEIGHT_SCREEN / 2;
            dest_ast.x = WIDTH_SCREEN;
        }
    }

    return Bool;

}

SDL_Rect* Asteroide::Position(){
    return &dest_ast;
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




void Asteroide::Render2(void) {
    SDL_RenderCopy(renderer, Texture_ast, NULL, &dest_ast);
}

void Asteroide::clean(){
	SDL_DestroyTexture(Texture_ast);
}
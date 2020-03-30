#include "../include/Asteroide.hpp"


Asteroide::Asteroide(SDL_Renderer *renderer, const char* path, float posX, float posY) 
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
    }
    SDL_FreeSurface(asteroide);


	angle = 0;

    SDL_QueryTexture(Texture_ast,&format, &access, &L, &H);

    src.x = 0;
	src.y = 0;
	src.w = L; 
	src.h = H;

    dest_ast.x = posX;
    dest_ast.y = posY;
    dest_ast.w = L;
    dest_ast.h = H;

    size = L * H ;

    do {
        speed.x = Random(-2, 2);
        speed.y = Random(-2, 2);
    }while (speed.x == 0 && speed.y == 0);
    
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


void Asteroide::Render(void) {
    SDL_RenderCopy(renderer, Texture_ast, NULL, &dest_ast);
}

void Asteroide::clean(){
	SDL_DestroyTexture(Texture_ast);
}
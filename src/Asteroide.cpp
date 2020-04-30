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

    dest_ast.x = posX;
    dest_ast.y = posY;
    dest_ast.w = L;
    dest_ast.h = H;

    size = L * H ;

    // Attribution d'une vitesse aléatoire à l'astéroide
    do {
        speed.x = Random(-2.0, 2.0);
        speed.y = Random(-2.0, 2.0);
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

void Asteroide::UpdateAsteroide(){
    // pendant le jeu
    dest_ast.x += speed.x;
    dest_ast.y += speed.y;

    // Si l'astéroide sort de l'écran on l'a fait apparaître 
    // sur le côté opposé à la même abscisse ou même ordonnée
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

    // Permet de savoir si les Rect de l'astéroide et du vaisseau ont une intersection
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
#include "../include/Asteroide.hpp"

const float SIZE_AST = 70; // a changer

Asteroide::Asteroide(SDL_Renderer *renderer, const char* path) 
{
    // SDL_Point center = { 300, 300};
    // SDL_Texture *Texture_ast;
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
        speed.x = RandomSpeed(-2, 2);
        speed.y = RandomSpeed(-2, 2);
    }while (speed.x == 0 && speed.y == 0);
    

    // position[0] = Asteroide::Random(0,HEIGHT_SCREEN);
    // position[1] = Asteroide::Random(0,WIDTH_SCREEN);

    //Box.w = SIZE_AST;
    //Box.h = Box.w;
    //Box.x = position[0];
    //Box.y = position[1] - Box.h

    // speed[0] = Asteroide::Random(0,100);
    // speed[1] = Asteroide::Random(0,100);

    // angle = Asteroide::Random(-2.0, 2.0); // A MODIFIER
    // angularSpeed = Asteroide::Random(-0.1,0.1); 

    dead = false ; 
    //size ; // = ?
}

Asteroide::~Asteroide(){
    SDL_DestroyTexture(Texture_ast);
}

// bool Asteroide::IsDead(){
//     // return dead; 
// }


void Asteroide::UpdateAsteroide(){
    // pendant le jeu
    dest_ast.x += speed.x;
    dest_ast.y += speed.y;

    // if (dest_ast.x <= 0 || dest_ast.x >= WIDTH_SCREEN || dest_ast.y <= 0|| dest_ast.y >= HEIGHT_SCREEN){
    //     dest_ast.x = Random(0, WIDTH_SCREEN);
    //     dest_ast.y = Random(0, HEIGHT_SCREEN);
    // }
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

// float Asteroide::GetSize(){
//     // return size;
// }

float Asteroide::Random(float x, float y){
    // fonction rendant un chiffre entre x et y
    if (x < y ){
       return ((float)rand() / (float)(RAND_MAX)) * (y-x) + x;
    }
    else{
        return ((float)rand() / (float)(RAND_MAX)) * (x-y) + y;
    }
}

float Asteroide::RandomSpeed(float x, float y){
    // fonction rendant un chiffre entre x et y
    return ((float)rand() / (float)(RAND_MAX)) * (x - y) + y;
    // return 1;
}


bool Asteroide::Collision(SDL_Rect* positionRocket){
    bool Bool = SDL_HasIntersection(&dest_ast, positionRocket);

    return Bool;
    
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



}


void Asteroide::Render2(void) {
    SDL_RenderCopy(renderer, Texture_ast, NULL, &dest_ast);
	//SDL_RenderCopyEx(renderer, Texture_ast, &src , &position, angle, NULL, SDL_FLIP_NONE);
}

void Asteroide::clean(){
	SDL_DestroyTexture(Texture_ast);
}
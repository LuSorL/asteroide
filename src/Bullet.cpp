#include "../include/Bullet.hpp"


Bullet::Bullet( SDL_Renderer *renderer, const char* path, float vaisseauX, float vaisseauY){
    SDL_Surface *bullet;
    this->renderer = renderer;

    Uint32 format;
    int a;
    int L;
    int H;

    bullet = SDL_LoadBMP(path);
    if (bullet == NULL ){
        std::cout << "Problem surface bullet" << SDL_GetError() << std::endl;
    }
    else {
        SDL_SetColorKey(bullet, SDL_TRUE, SDL_MapRGB(bullet->format, 255, 255, 255));
        Texture_bullet = SDL_CreateTextureFromSurface(renderer, bullet);
        if (Texture_bullet == NULL ){
            std::cout << "Problem texture bullet" << SDL_GetError() << std::endl;
        }
    }
    SDL_FreeSurface(bullet);

    // Pour que le missile ne parte pas du centre du vaisseau
    x = vaisseauX + 70;
    y = vaisseauY + 10;


    SDL_QueryTexture(Texture_bullet,&format, &a, &L, &H);

    dest_bullet.x = x;
    dest_bullet.y = y;
    dest_bullet.w = L;
    dest_bullet.h = H;

}

void Bullet::clean(){
    SDL_DestroyTexture(Texture_bullet);
}

SDL_Rect* Bullet::Position(){
    SDL_Rect* pos = &dest_bullet;
    return pos;
}

SDL_Texture* Bullet::Texture(){
    return Texture_bullet;
}

/* Detecte les collisions entre le missile et l'astéroide */
bool Bullet::Collision(SDL_Rect* positionAst){

    bool Bool = SDL_HasIntersection(&dest_bullet, positionAst);

    return Bool;

}

Bullet::~Bullet(){}

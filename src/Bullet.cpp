#include "../include/Bullet.hpp"


Bullet::Bullet( SDL_Renderer *renderer, const char* path, float vaisseauX, float vaisseauY, float angleV)
//SDL_Renderer *renderer, const char* path, float vaisseauX, float vaisseauY, float angleV
{
    SDL_Surface *bullet;
    this->renderer = renderer;
    
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
        else {
            // Box va contenir bullet pour détecter les collisions par la suite
            Box.w = bullet->w;
            Box.h = bullet->h;
        }
    }
    SDL_FreeSurface(bullet);
    


    Vx = static_cast<float>(sin(2 * PI * (angleV / 360))) * 5;
	Vy = static_cast<float>(-cos(2 * PI * (angleV / 360))) * 5;

    x = vaisseauX + 70;
    y = vaisseauY + 10;

    
    SDL_QueryTexture(Texture_bullet,&format, &a, &L, &H);

    dest_bullet.x = x;
    dest_bullet.y = y;
    dest_bullet.w = L;
    dest_bullet.h = H;
    
    angle = 0;
    //angularSpeed = 0;

    //createdNow = GetTickCount();
    apparitionTime = 1000; 
}

bool Bullet::Remove()
{
    /*
    if ( GetTickCount() - createdNow >= apparitionTime){
        return true;
    }
    */
	return false;
    
}

void Bullet::Render2(float posX, float posY) {
    dest_bullet.x = posX;
    dest_bullet.y = posY;
    SDL_RenderCopy(renderer, Texture_bullet, NULL, &dest_bullet);
}

void Bullet::clean(){
    SDL_DestroyTexture(Texture_bullet);
}

void Bullet::move(float angle){
    x = cos(PI * angle /180)*60;
	y = sin(PI * angle /180)*60 ;

	dest_bullet.x += x;
	dest_bullet.y += y;
    
}

/*
void Bullet::Draw(float x, float y , float angle){
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF );		
	SDL_RenderDrawLine( renderer, x, y , cos(PI * angle /180)*10 , sin(PI * angle /180)*10);
}
*/

SDL_Rect* Bullet::Position(){
    SDL_Rect* pos = &dest_bullet;
    return pos;
}

/*
void Bullet::handleEvent(SDL_Event &e, float angle){
    if( e.type == SDL_KEYDOWN ){
		switch( e.key.keysym.sym){
			case SDLK_ESCAPE : 
				quit = 1;
				break;
            case SDLK_SPACE :
                move(angle);
                break;

		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0){
		switch( e.key.keysym.sym){
			case SDLK_ESCAPE : 
				quit = 1;
				break;
            case SDLK_SPACE :
                move(angle);
                break;

		}
	}
}
*/
Bullet::~Bullet()
{
	//vaisseau.EndFire();
}
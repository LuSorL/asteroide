#include "vaisseau.hpp"

const float PI = 3.14159265359f;

vaisseau::vaisseau(SDL_Renderer *renderer, std::string path) : angularSpeed(0.2f), accelerationFactor( 0.2f) , Game()
{
	SDL_Surface *rocket;
	rocket = SDL_LoadBMP(path);
	if ( rocket == NULL ){
		std::cout << " Load image rocket" << SDL_GetError() << std::endl;
	}
	else {
		SDL_SetColorKey(rocket, SDL_TRUE, SDL_MapRGB(rocket->format, 255, 255, 255));
        Texture_rocket = SDL_CreateTextureFromSurface(renderer, rocket);
        if (Texture_rocket == NULL ){
            std::cout << "Problem texture rocket" << SDL_GetError() << std::endl;
        }
		else{
			// RenderRect sera utilisé pour les collisions
			RenderRect.h = rocket->h;
			RenderRect.w = rocket->w;
		}
	}
	SDL_FreeSurface(rocket);

	// Position intiale du vaisseau
	x = W_WIDTH/2 - (RenderRect.w)/2 ;
	y = W_HEIGHT/2 - (RenderRect.h)/2 ;  
	height = 100; // valeur au pif
	width = 100;  // same
	angle = 0f;
	angularSpeed = 0f;
	credit = 3; // nombre de vies
    bulletCoolDown = 100; // en ms
}

vaisseau::~vaisseau(){
	SDL_DestroyTexture(Texture_rocket);
}

void vaisseau::ResetBulletCoolDown(){
        lastBulletTime = 0;
}

void vaisseau::Reset(){
	x = static_cast<float>(W_WIDTH) / 2;
	y = static_cast<float>(W_HEIGHT) / 2;
	angle = 0;
	velocityX = velocityY = 0;

	// No bullets fired yet
	lastBulletTime = 0;
	bulletUsed = 0;
	credit--;
}

void vaisseau::Rotate( int direction){
        angle += direction * angularSpeed ;  // direction = +1 ou -1 
}

void vaisseau::moveLeft(){
	x -= 20;
}

void vaisseau::moveRight(){
	x += 20;
}

void vaisseau::Acceleration(){
        // Create a normalized vector in the direction of travel
	float xN = static_cast<float>(sin(2 * PI * (angle / 360)));
	float yN = static_cast<float>(cos(2 * PI * (angle / 360)));

	vX += xN * accelerationFactor;
	vY -= yN * accelerationFactor;
}

Bullet *vaisseau::Fire()
{
	if (GetTickCount() - lastBulletTime >= bulletCooldown){
	        if (bulletUsed < maxBullets){
		Bullet *bullet = new Bullet(renderer, *this, x, y, angle);
		lastBulletTime = GetTickCount();
		bulletUsed++;
		return bullet;
		}
	}
	return NULL;
}

void vaisseau::EndFire(){
        bulletUsed = max(bulletUsed - 1, 0);
}

void vaisseau::Render(){

	RenderRect.x = x;
	RenderRect.y = y;
	RenderRect.h = height;
	RenderRect.w = width;
	SDL_RenderCopy(renderer, texture, NULL, &renderRect);

	mainColliderRect.x = x + 25;
	mainColliderRect.y = y;
	mainColliderRect.h = height;
	mainColliderRect.w = 50;

	leftColliderRect.x = x;
	leftColliderRect.y = y + 50;
	leftColliderRect.h = 40;
	leftColliderRect.w = 25;

	rightColliderRect.x = x + 75;
	rightColliderRect.y = y + 50;
	rightColliderRect.h = 40;
	rightColliderRect.w = 25;

	//Render Colliders
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &leftColliderRect);
	SDL_RenderDrawRect(renderer, &mainColliderRect);
	SDL_RenderDrawRect(renderer, &rightColliderRect);

	SDL_Point center; // valeur ?
    int A, L,H; // Où les déclarer ?
    Uint32 format1; 
    SDL_QueryTexture(Texture_rocket,&format1, &A, &L, &H);
    SDL_Rect src = {0,0, H, L}; // valeur à modifier
    SDL_Rect dest_ast = { W_WIDTH/2-L/2 , W_HEIGHT/2-H/2, H, L};
    int result = SDL_RenderCopyEx(renderer, Texture_rocket, &src , &Box, angle, &center, SDL_FLIP_NONE);
	if ( result != 0 ){
        std::cout << "result " << SDL_GetError() << std::endl;
    }
}
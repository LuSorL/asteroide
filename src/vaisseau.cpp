#include "../include/vaisseau.hpp"
#include "../include/Bullet.hpp"
#include<cstdio>


vaisseau::vaisseau(SDL_Renderer *renderer, const char* path)
{
	SDL_Surface *rocket;
	this->renderer = renderer;
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
	x = WIDTH_SCREEN/2 - (RenderRect.w)/2 ;
	y = HEIGHT_SCREEN/2 - (RenderRect.h)/2 ;  

	angle = 0;

	SDL_QueryTexture(Texture_rocket, &format, &a, &width, &height);
	
	src.x = 0;
	src.y = 0;
	src.w = width ; 
	src.h = height;

	positionRocket.x = x ;
	positionRocket.y = y ;
	positionRocket.w = width ;
	positionRocket.h = height ;
  
	credit = 100; // nombre de vies
    bulletCoolDown = 100; // en ms
}

vaisseau::~vaisseau(){
	for(int i = 0; i < NB_MIS; ++i)
	{
		if(missile[i])
			delete missile[i];
	}

	//missile.clear();
	SDL_DestroyTexture(Texture_rocket);
}


void vaisseau::ResetBulletCoolDown(){
    lastBulletTime = 0;
}

void vaisseau::Reset(){
	x = static_cast<float>(WIDTH_SCREEN) / 2;
	y = static_cast<float>(HEIGHT_SCREEN) / 2;
	angle = 0;
	vX = vY = 0;

	// No bullets fired yet
	lastBulletTime = 0;
	bulletUsed = 0;
	credit--;
}

void vaisseau::Rotate( int direction){
    angle += direction * ANGULARSPEED ;  // direction = +1 ou -1 
	//angle = 360 % static_cast<int>(angle);
}


void vaisseau::moveUp(float angle){

	xN = cos(PI * angle /180)*30;
	yN = sin(PI * angle /180)*30 ;

	positionRocket.x += xN;
	positionRocket.y += yN;

	if( positionRocket.x < 0 || (positionRocket.x + RenderRect.w > WIDTH_SCREEN)){
		positionRocket.x -= xN ;
	}

	if (positionRocket.y < 0 || (positionRocket.y + RenderRect.h > HEIGHT_SCREEN)){
		positionRocket.y -= yN ;
	}
}

void vaisseau::moveDown(float angle){
	xN = cos(PI * angle /180)*30 ;
	yN = sin(PI * angle /180)*30 ;

	positionRocket.x += xN;
	positionRocket.y += yN;

	if( positionRocket.x < 0 || (positionRocket.x + RenderRect.w > WIDTH_SCREEN)){
		positionRocket.x -= xN ;
	}

	if (positionRocket.y < 0 || (positionRocket.y + RenderRect.h > HEIGHT_SCREEN)){
		positionRocket.y -= yN;
	}
}

void vaisseau::Acceleration(){
        // Create a normalized vector in the direction of travel
	float xN = static_cast<float>(sin(2 * PI * (angle / 360)));
	float yN = static_cast<float>(cos(2 * PI * (angle / 360)));

	vX += xN * accelerationFactor;
	vY -= yN * accelerationFactor;
}



void vaisseau::Render(){

	RenderRect.x = x;
	RenderRect.y = y;
	RenderRect.h = height;
	RenderRect.w = width;
	SDL_RenderCopy(renderer, texture, NULL, &RenderRect);

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

}


/*
void vaisseau::Draw(){
	Bullet* temp = Missile(bulletUsed);
	float x_t = temp->Position()->x;
	float y_t = temp->Position()->y;
	temp->Draw(x_t,y_t,angle);
	//std::cout << "Succes" << std::endl;
}
*/

void vaisseau::Render2(void) {
	SDL_RenderCopyEx(renderer, Texture_rocket, &src , &positionRocket, angle, NULL, SDL_FLIP_NONE);
}

void vaisseau::handleEvent(SDL_Event &e, SDL_Texture* texture, SDL_Rect &dest){
	if( e.type == SDL_KEYDOWN ){
		switch( e.key.keysym.sym){
			case SDLK_ESCAPE : 
				quit = 1;
				break;
			case SDLK_RIGHT :
				vaisseau::Rotate(1);
				break;
			case SDLK_LEFT :
				vaisseau::Rotate(-1);
				break;
			case SDLK_UP :
				moveUp(angle);
				break;
				/*
			case SDLK_DOWN :
				moveDown(angle);
			break;
			*/
			case SDLK_SPACE :
				Compte();
			break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0){
		switch( e.key.keysym.sym){
			case SDLK_ESCAPE : 
				quit = 1;
				break;
			case SDLK_RIGHT :
				vaisseau::Rotate(1);
				break;
			case SDLK_LEFT :
				vaisseau::Rotate(-1);
				break;
			case SDLK_UP :
				moveUp(angle);
				break;
				/*
			case SDLK_DOWN :
				moveDown(angle);
			break;
			*/
		}
	}
}

float vaisseau::getAngle(){
	return angle;
}

void vaisseau::clean(){
	SDL_DestroyTexture(Texture_rocket);
}

bool vaisseau::IsDead(){
	if (credit <= 0){
		return true;
	}
	else {
		return false;
	}
}

void vaisseau::UpdateCredit(int i){
	std::cout << credit << std::endl;
	credit += i;
}

SDL_Rect* vaisseau::Position(){
	SDL_Rect* pos = &positionRocket;
	return pos;
}



/*------------------------- BULLET ----------------------------*/ 

void vaisseau::Update_bullet(){

	for(int i = 0; i < NB_MIS; ++i) {
		if(missile[i]) {
			if( (missile[i]->Position()->x < 0) || (missile[i]->Position()->y < 0) ||
			   (missile[i]->Position()->x > WIDTH_SCREEN) || (missile[i]->Position()->y > HEIGHT_SCREEN))
			{
				delete missile[i];
				//missile.erase(missile.begin() + i);
				--i;
			} else
				missile[i]->Position()->x += SPEED;
				missile[i]->Position()->y += SPEED;
				
		}
	}
}

int vaisseau::Compte(){
	if (bulletUsed < NB_MIS){
		bulletUsed++;
	}
	else{
		bulletUsed = 0;
		Fire();
		Update_bullet();
	}
	return bulletUsed;
}


Bullet* vaisseau::Missile(int i){
	return missile[i];
}

void vaisseau::EndFire(){
    bulletUsed = std::max(bulletUsed - 1, 0);
}

void vaisseau::Fire()
{
	bulletUsed = 0;
	for(int i = 0; i < NB_MIS; ++i) {
		//if(missile[i])
		missile[i] = new Bullet(renderer,"./src/laser.bmp", positionRocket.x, positionRocket.y, angle);
	}
 	/*
	if (bulletUsed < MAX_BULLETS){
		
		bullet = new Bullet(renderer,"./src/laser.bmp", positionRocket.x, positionRocket.y, angle);
		//std::cout << bullet->Position()->x << std::endl;
		//lastBulletTime = 1; // = GetTickCount(); ??????
		bulletUsed++;
		return bullet;
	}
	*/
	/*
	if (GetTickCount() - lastBulletTime >= bulletCoolDown){
	    
	}
	*/
	//return NULL;
}


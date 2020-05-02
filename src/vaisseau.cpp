#include "../include/vaisseau.hpp"
#include "../include/Bullet.hpp"



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
	src.w = width; 
	src.h = height;

	positionRocket.x = x ;
	positionRocket.y = y ;
	positionRocket.w = width ;
	positionRocket.h = height ;
  
	credit = CREDIT; // nombre de vies
	score = 0 ;
}

vaisseau::~vaisseau(){
	std::cout<< " Je suis le destructeur de Rocket" << std::endl;

}

void vaisseau::Rotate( int direction){
    angle += direction * ANGULARSPEED ;  // direction = +1 ou -1 
}


void vaisseau::move(float angle){

	xN = cos(PI * angle /180)* SPEED;
	yN = sin(PI * angle /180)* SPEED ;

	positionRocket.x += xN;
	positionRocket.y += yN;

	/* Empêche l'astéroide de sortir de la fenêtre */
	if( positionRocket.x < 0 || (positionRocket.x + RenderRect.w > WIDTH_SCREEN)){
		positionRocket.x -= xN ;
	}

	if (positionRocket.y < 0 || (positionRocket.y + RenderRect.h > HEIGHT_SCREEN)){
		positionRocket.y -= yN ;
	}
}



void vaisseau::Render(void) {
	SDL_RenderCopyEx(renderer, Texture_rocket, &src , &positionRocket, angle, NULL, SDL_FLIP_NONE);
}

void vaisseau::handleEvent(){
	const Uint8 *keystates = SDL_GetKeyboardState( NULL );

	if( keystates[ SDL_SCANCODE_UP ] ){
		move(angle);
	}

	if( keystates[ SDL_SCANCODE_RIGHT ] ){
		Rotate(1);
	}
	
	if( keystates[ SDL_SCANCODE_LEFT ] ){
		Rotate(-1);
	}

	if( keystates[ SDL_SCANCODE_RIGHT ] && keystates[SDL_SCANCODE_UP] ){
		move(angle);
		Rotate(1);
	}

	if( keystates[ SDL_SCANCODE_LEFT ] && keystates[SDL_SCANCODE_UP] ){
		move(angle);
		Rotate(-1);
	}

	if( keystates[ SDL_SCANCODE_SPACE ] ){
		Fire();
	}

}

float vaisseau::getAngle(){
	return angle;
}

SDL_Rect* vaisseau::Position(){
	SDL_Rect* pos = &positionRocket;
	return pos;
}

void vaisseau::UpdateCredit(int i){
	credit += i;
}

int vaisseau::Credit(){
	return credit;
}

void vaisseau::UpdateScore(int i){
	score += i;
}

int vaisseau::Score(){
	return score;
}

bool vaisseau::IsDead(){
	if (credit <= 0){
		return true;
	}
	else {
		return false;
	}
}

void vaisseau::clean(){
	for(size_t i = 0; i < missile.size(); i++)
	{
		if( missile[i] ){

			delete missile[i];

		}
			
	}
	SDL_DestroyTexture(Texture_rocket);
}


/*------------------------- BULLET ----------------------------*/ 

void vaisseau::Update_bullet(){

	for (size_t i = 0 ; i < missile.size() ; i++ ){
		if ((missile[i]->Position()->x < 0) || (missile[i]->Position()->y < 0) ||
		(missile[i]->Position()->x > WIDTH_SCREEN) || (missile[i]->Position()->y > HEIGHT_SCREEN)){
			delete missile[i];
			missile.erase(missile.begin() + i);
			i--;
		}
		else {
			missile[i]->Position()->x += cos(PI * angle /180)* SPEED_MISSILE;
			missile[i]->Position()->y += sin(PI * angle /180)* SPEED_MISSILE;
		}
	}
}

void vaisseau::Render_bullet(){

	for ( size_t i = 0 ; i < missile.size() ; i++){
		SDL_RenderCopy(renderer, missile[i]->Texture(), NULL, missile[i]->Position());
	}

}

Bullet* vaisseau::Fire()
{	
	if (bulletUsed < MAX_BULLETS){
		
		bullet = new Bullet(renderer,"./src/laser.bmp", positionRocket.x, positionRocket.y, angle);
		bulletUsed++;
		missile.push_back( bullet );

		return bullet;
		
	}
	return NULL;
}

int vaisseau::MissileSize(){
	return missile.size();
}

void vaisseau::Erase( int j ){
	missile.erase(missile.begin() + j);
}

Bullet* vaisseau::Missile( int i ){
	return missile[i];
}



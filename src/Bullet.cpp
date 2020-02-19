#include "../include/Bullet.hpp"
const float PI = 3.14159265359f;

Bullet::Bullet( SDL_Renderer *renderer, int vaisseauX, int vaisseauY, float angleV) //: vaisseau(renderer, "vaisseauR.bmp") //Game 
{
    // load picture ?

    Vx = static_cast<float>(sin(2 * PI * (angleV / 360))) * 5;
	Vy = static_cast<float>(-cos(2 * PI * (angleV / 360))) * 5;

    x = vaisseauX;
    y = vaisseauY;

    angle = 0;
    angularSpeed = 0;

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

Bullet::~Bullet()
{
	//vaisseau.EndFire();
}
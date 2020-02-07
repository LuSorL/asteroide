#include "Bullet.h"

Bullet::Bullet( int vaisseauX, int vaisseauY, float angleV) : vaisseau(v), //Game 
{
    // load picture ?

    vX = static_cast<float>(sin(2 * PI * (angleV / 360))) * 5;
	vY = static_cast<float>(-cos(2 * PI * (angleV / 360))) * 5;

    x = vaisseauX;
    y = vaisseauY;

    angle = 0f;
    angularSpeed = 0f;

    createdNow = GetTickCount();
    apparitionTime = 1000; 
}

bool Bullet::Remove()
{
    if ( GetTickCount() - createdNow >= apparitionTime){
        return true;
    }
	return false;
}

Bullet::~Bullet()
{
	vaisseau.EndFire();
}
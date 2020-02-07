//#ifndef BULLET_HPP  
//#define BULLET_HPP
#include "SDL.h"

class Bullet {
    public : 
    
    ~Bullet();
    Bullet( int vaisseauX, int vaisseauY, float angleV);
    bool Remove();

    protected : 
    int x;
    int y;
    int Vx,Vy;
    int speed;
    float angle;
    float angularSpeed;
    int appartionTime ; // durée d'apparition en ms 
    int createdNow;  // instant t de création de la balle

};
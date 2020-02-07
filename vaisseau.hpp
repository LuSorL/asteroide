// #ifndef VAISSEAU_HPP  
// #define VAISSEAU_HPP
#include "./include/SDL2/SDL.h"

class vaisseau {
    public : 
    vaisseau(SDL_Renderer *renderer, std::string path);
    ~vaisseau();
    void Reset(); //Reset Game
    void Rotate(); // rotation du vaisseau
    void moveLeft();
    void moveRight();
    void ResetBulletCoolDown();
    void Acceleration();
    Bullet* Fire();
    void EndFire();
    void Render();
    
    protected :
    int velocityX; // vitesse du vaisseau
    int velocityY;
    int x, y; // position du vaisseau
    int width;
    int height;
    float angle; 
    float angularSpeed;
    float accelerationFactor;
    int credit; // Vie
    int bulletCoolDown;
    int lastBulletTime ; 
    int maxBullet;
    int bulletUsed; 

};
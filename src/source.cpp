#include "../include/Game.hpp"

int main(void){

    Game jeu;

    if(!jeu.initialization()){
        jeu.run();
    }

    jeu.clean();
    return 0;
}

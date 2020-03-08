#include "../include/Game.hpp"

int main(int argc, char* argv[]){
    
    Game jeu;

    if(!jeu.initialization()){
        jeu.run();
    }
    
    jeu.clean();
    return 0;
}
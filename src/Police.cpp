#include "Police.hpp"

SDL_Surface* surfacePolice(std::string file, int size, std::string text, SDL_Color couleur) {

    //Ouvre la police
    TTF_Font* police = TTF_OpenFont(file.c_str(), size);

    //Ecriture du texte passé dans une surface
    SDL_Surface* surfaceText = TTF_RenderText_Blended(police, text.c_str(), couleur);

    //Libère la mémoire utilisé par la police
    TTF_CloseFont(police);

    //Retourne la surface texte
    return surfaceText;
}
#include "../include/Texture.hpp"

Texture::Texture(SDL_Renderer* renderer, SDL_Color textColor, int score){

    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, " Test ", textColor );

	if( textSurface == NULL )
	{
		std::cout << " Problem Write surface " << TTF_GetError() << std::endl;
	}
	else
	{
        Texture_Surface = SDL_CreateTextureFromSurface( renderer, textSurface );

		if( Texture_Surface == NULL )
		{
			std::cout << " Problem Texture_Surface Write" << SDL_GetError() << std::endl;
		}
		else
		{
			Width = textSurface->w;
			Height = textSurface->h;
		}

		SDL_FreeSurface( textSurface );
	}
}

Texture::~Texture(){}

void Texture::Write(){

    gFont = TTF_OpenFont( "lazy.ttf", 28 );

	if( gFont == NULL )
	{
		std::cout << " problème gfont " << TTF_GetError() << std::endl;
	}
    else{
        SDL_Color textcolor = { 0,0,0 };
    }
}

void Texture::Render(){
    
}

void clean(){
    TTF_Quit();
}
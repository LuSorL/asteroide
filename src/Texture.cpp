#include "../include/Texture.hpp"

Texture::Texture(){
	Texture_Surface = NULL;
	Width = 0;
	Height = 0;
}

Texture::~Texture(){
	clean();
	std::cout << "Je suis le destructeur de Texture " << std::endl;
}

void Texture::clean()
{
	//Free texture 
	if( Texture_Surface != NULL && Texture_SurfaceScore != NULL &&
	Texture_SurfaceCred != NULL && Texture_SurfaceCredit != NULL)
	{
		SDL_DestroyTexture( Texture_Surface );
		SDL_DestroyTexture( Texture_SurfaceScore );
		SDL_DestroyTexture( Texture_SurfaceCred );
		SDL_DestroyTexture( Texture_SurfaceCredit );
		Texture_Surface = NULL;
		Texture_SurfaceScore = NULL;
		Texture_SurfaceCred = NULL;
		Texture_SurfaceCredit = NULL;
		Width  = 0;
		WidthScore = 0;
		WidthCred = 0;
		WidthCredit = 0;
		Height = 0;
		HeightScore = 0;
		HeightCred = 0;
		HeightCredit = 0;
	}
}

bool Texture::loadFromRenderedText( SDL_Renderer *renderer, int score, int credit)
{
	//Convertir les int en string pour les afficher
	std::string score_string = std::to_string(score);
	std::string credit_string = std::to_string(credit);

	std::string print_score = "Score : ";
	std::string print_credit = "Credits : ";

	//Render text surface
	SDL_Surface* textSurfaceScore = TTF_RenderText_Solid( gFont, print_score.c_str(), textColor );
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, score_string.c_str(), textColor );
	SDL_Surface* textSurfaceCredit = TTF_RenderText_Solid( gFont, credit_string.c_str(), textColor );
	SDL_Surface* textSurfaceCred = TTF_RenderText_Solid( gFont, print_credit.c_str(), textColor );

	if( textSurface == NULL  && textSurfaceScore==NULL && textSurfaceCred==NULL
	&& textSurfaceCredit==NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		Texture_SurfaceCred = SDL_CreateTextureFromSurface( renderer, textSurfaceCred );
		Texture_SurfaceCredit = SDL_CreateTextureFromSurface( renderer, textSurfaceCredit );
        Texture_Surface = SDL_CreateTextureFromSurface( renderer, textSurface );
		Texture_SurfaceScore = SDL_CreateTextureFromSurface( renderer, textSurfaceScore );
		if( Texture_Surface == NULL && Texture_SurfaceScore == NULL
		&& Texture_SurfaceCred==NULL && Texture_SurfaceCredit==NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			// Dimensions des surfaces
			Width = textSurface->w;
			Height = textSurface->h;

			WidthScore = textSurfaceScore->w;
			HeightScore = textSurfaceScore->h;

			WidthCred = textSurfaceCred->w;
			HeightCred = textSurfaceCred->h;

			WidthCredit = textSurfaceCredit->w;
			HeightCredit = textSurfaceCredit->h;
		}

	
		SDL_FreeSurface( textSurface );
		SDL_FreeSurface( textSurfaceScore );
		SDL_FreeSurface( textSurfaceCred );
		SDL_FreeSurface( textSurfaceCredit );
	}
	
	//Return success
	return (Texture_Surface != NULL && Texture_SurfaceScore != NULL && Texture_SurfaceCred != NULL && Texture_SurfaceCredit != NULL) ;
}

void Texture::Render(SDL_Renderer *renderer)
{
	
	positionScore.x = 20 ;
	positionScore.y = 20 ;
	positionScore.h = HeightScore;
	positionScore.w = WidthScore;

	position.x = positionScore.x + WidthScore + 7 ;
	position.y = positionScore.y ;
	position.h = Height;
	position.w = Width;

	positionCred.x = positionScore.x ;
	positionCred.y = positionScore.y + HeightScore + 20 ;
	positionCred.h = HeightCred;
	positionCred.w = WidthCred;

	positionCredit.x = positionCred.x + WidthCred + 10 ;
	positionCredit.y = positionCred.y ;
	positionCredit.h = HeightCredit;
	positionCredit.w = WidthCredit;

	// Affichage Score et Credits
	SDL_RenderCopy(renderer, Texture_SurfaceScore, NULL, &positionScore);
	SDL_RenderCopy(renderer, Texture_Surface, NULL, &position);

	SDL_RenderCopy(renderer, Texture_SurfaceCredit, NULL, &positionCredit);
	SDL_RenderCopy(renderer, Texture_SurfaceCred, NULL, &positionCred);

}

bool Texture::loadMedia(SDL_Renderer * renderer, int score, int credit)
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont( "./src/lazy.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		// Couleur du texte
		textColor.r = 255;
		textColor.g = 255;
		textColor.b = 255;
		if( !loadFromRenderedText( renderer, score, credit) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}


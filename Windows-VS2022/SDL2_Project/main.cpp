#include <iostream>
#include <cstdlib>

#include "SDL.h"
//Include SDL_image this library provides
//support for loading different types of images.
#include "SDL_image.h"
	
int main(int argc, char** argv)
{
	// Declare window and renderer objects
	SDL_Window* gameWindow = nullptr;
	SDL_Renderer* gameRenderer = nullptr;

	SDL_Init(SDL_INIT_EVERYTHING);
	// Temporary surface used while loading the image
	SDL_Surface* temp = nullptr;

	// Texture which stores the actual sprite (this
	// will be optimised).
	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* playerTexture = nullptr;

	/**********************************
	 *    Setup background image     *
	 * ********************************/

	 //Use the SDL_image library rather than SDL.
	 // Load the sprite to our temp surface
	temp = IMG_Load("assets/images/background.png");

	// Create a texture object from the loaded image
	// - we need the renderer we're going to use to draw this as well!
	// - this provides information about the target format to aid optimisation.
	backgroundTexture = SDL_CreateTextureFromSurface(gameRenderer, temp);

	// Clean-up - we're done with 'image' now our texture has been created
	SDL_FreeSurface(temp);
	temp = nullptr;

	/**********************************
	*    Setup player image     *
	* ********************************/

	//Use the SDL_image library rather than SDL.
	// Load the sprite to our temp surface
	temp = IMG_Load("assets/images/dorf3.png");

	// Create a texture object from the loaded image
	// - we need the renderer we're going to use to draw this as well!
	// - this provides information about the target format to aid optimisation.
	playerTexture = SDL_CreateTextureFromSurface(gameRenderer, temp);

	// Clean-up - we're done with 'image' now our texture has been created
	SDL_FreeSurface(temp);
	temp = nullptr;

	gameWindow = SDL_CreateWindow(
		"Hello GDV4001",          // Window title
		SDL_WINDOWPOS_UNDEFINED,  // X position
		SDL_WINDOWPOS_UNDEFINED,  // Y position
		800, 600,                 // width, height
		SDL_WINDOW_SHOWN);        // Window flags

	// Create our renderer
	gameRenderer = SDL_CreateRenderer(gameWindow, 0, 0);
	// 1. Clear the screen
	SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);

	// Colour provided as red, green, blue and alpha 
	//(transparency) values (i.e. RGBA)
	SDL_RenderClear(gameRenderer);
// 2. Draw the image
	SDL_RenderCopy(gameRenderer, backgroundTexture, NULL, NULL);
	SDL_RenderCopy(gameRenderer, playerTexture, NULL, NULL);
// 3. Present the current frame to the screen
    SDL_RenderPresent(gameRenderer);
	
	//Pause to allow the image to be seen
	SDL_Delay(10000);
//Clean up!
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);

	//Shutdown SDL - clear up resources etc. 
	SDL_Quit();

	// exit the program
	exit(0);
	exit(EXIT_SUCCESS);
}
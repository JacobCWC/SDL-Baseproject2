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
	SDL_Texture* goblinSpriteSheet = nullptr;
	// Source Rectangles
 // ... other source rectangles. 
	SDL_Rect goblinSourceRectangle;

	// Goblin size in sprite sheet. 
	const int GOBLIN_W = 65;
	const int GOBLIN_H = 64;

	// Destination Rectangle
	SDL_Rect goblinDestRectangle;

	gameWindow = SDL_CreateWindow(
		"Hello GDV4001",          // Window title
		SDL_WINDOWPOS_UNDEFINED,  // X position
		SDL_WINDOWPOS_UNDEFINED,  // Y position
		800, 600,                 // width, height
		SDL_WINDOW_SHOWN);        // Window flags

	// Create our renderer
	gameRenderer = SDL_CreateRenderer(gameWindow, 0, 0);	gameWindow = SDL_CreateWindow(
		"Hello GDV4001",          // Window title
		SDL_WINDOWPOS_UNDEFINED,  // X position
		SDL_WINDOWPOS_UNDEFINED,  // Y position
		800, 600,                 // width, height
		SDL_WINDOW_SHOWN);        // Window flags

	// Create our renderer
	gameRenderer = SDL_CreateRenderer(gameWindow, 0, 0);

	/**********************************
  *  Setup goblin sprites sheet    *
  * ********************************/

  //Use the SDL_image library rather than SDL.
  // Load the sprite to our temp surface
	temp = IMG_Load("assets/images/goblinSpear.png");

	// Create a texture object from the loaded image
	// - we need the renderer we're going to use to draw this as well!
	// - this provides information about the target format to aid optimisation.
	goblinSpriteSheet = SDL_CreateTextureFromSurface(gameRenderer, temp);

	// Clean-up - we're done with 'image' now our texture has been created
	SDL_FreeSurface(temp);
	temp = nullptr;

	/**********************************
	*    Setup source rectangles      *
	* ********************************/

	// .. source info for other images.

	goblinSourceRectangle.x = 0;
	goblinSourceRectangle.y = 0;
	goblinSourceRectangle.w = GOBLIN_W;
	goblinSourceRectangle.h = GOBLIN_H;

	/**********************************
	 * Setup destination rectangles   *
	 * ********************************/

	goblinDestRectangle.x = 600;
	goblinDestRectangle.y = 200;
	goblinDestRectangle.w = GOBLIN_W;
	goblinDestRectangle.h = GOBLIN_H;

	// Clean-up - we're done with 'image' now our texture has been created
	SDL_FreeSurface(temp);
	temp = nullptr;


	// 1. Clear the screen
	SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);

	// Colour provided as red, green, blue and alpha 
	//(transparency) values (i.e. RGBA)
	SDL_RenderClear(gameRenderer);
// 2. Draw the image
	 // ... draw background image 
	SDL_RenderCopy(gameRenderer, goblinSpriteSheet, &goblinSourceRectangle, &goblinDestRectangle);
// 3. Present the current frame to the screen
    SDL_RenderPresent(gameRenderer);
	
	//Pause to allow the image to be seen
	SDL_Delay(10000);
//Clean up!
	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyTexture(goblinSpriteSheet);
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);

	//Shutdown SDL - clear up resources etc. 
	SDL_Quit();

	// exit the program
	exit(0);
	exit(EXIT_SUCCESS);
}
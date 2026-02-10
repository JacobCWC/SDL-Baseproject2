#include <iostream>
#include <cstdlib>

#include "SDL.h"

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	std::cout << "Hello World" << std::endl;

	exit(EXIT_SUCCESS);
}
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "Tengine.h"
namespace Tengine{
	int init() {
		SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}

}
#include"Event.h"
bool Event::ProcessEvents() { // event for closing window
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			return false;
	}
	return true;
}
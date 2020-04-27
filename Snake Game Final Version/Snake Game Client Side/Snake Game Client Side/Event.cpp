#include"Event.h"
void Event::ProcessEvents(Direction& direction) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			direction = Direction::EXIT;

		else if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				direction = direction != Direction::DOWN ? Direction::UP : direction;
				break;
			case SDLK_DOWN:
				direction = direction != Direction::UP ? Direction::DOWN : direction;
				break;
			case SDLK_RIGHT:
				direction = direction != Direction::LEFT ? Direction::RIGHT : direction;
				break;
			case SDLK_LEFT:
				direction = direction != Direction::RIGHT ? Direction::LEFT : direction;
				break;

			case SDLK_1:
				Screen::FPS = 20;
				break;
			case SDLK_2:
				Screen::FPS = 25;
				break;
			case SDLK_3:
				Screen::FPS = 30;
				break;
			case SDLK_4:
				Screen::FPS = 40;
				break;
			default:
				break;
			}

		else if (event.key.keysym.sym == SDLK_a)
		{
			while (1) {
				SDL_PollEvent(&event);
				if (event.key.keysym.sym == SDLK_s) break;
				else if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				{
					direction = Direction::EXIT;
					break;
				}
			}
		}
	}
}
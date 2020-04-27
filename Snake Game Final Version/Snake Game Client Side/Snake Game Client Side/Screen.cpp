#include"Screen.h"

#define SDLFailed(x)  std::cout <<  x <<"   err " << SDL_GetError() << std::endl;

Screen::Screen(Uint32* buffer) :m_window(NULL), m_renderer(NULL), m_texture(NULL), m_Initialize(true) {
	this->m_buffer = buffer;
	LastTick = 0;
	SpeedV = 11.0;
}


bool Screen::Initialize() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDLFailed("Unable initialize SDL.");
		m_Initialize = false;
		return false;
	}

	m_window = SDL_CreateWindow("Snake Game Client Side", 730, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 
	if (m_window == NULL) {
		SDLFailed("Unable create a window.");
		m_Initialize = false;
		SDL_Quit();
		return false;
	}


	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL) {
		SDLFailed("Unable create a renderer.");
		m_Initialize = false;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}


	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_texture == NULL) {
		SDLFailed("Unable create a texture.");
		m_Initialize = false;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}


	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	Frame();

	return true;
}

void Screen::Frame() {
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			if (x - 11 < 0) {
				SetPixel(x, y, BLUE);
			}
			if (y - 11 < 0) {
				SetPixel(x, y, BLUE);
				SetPixel(x, SCREEN_HEIGHT - 1 - y, BLUE);
			}
		}
	}
}

void Screen::SetPixel(int x, int y, Uint32 color) {
	m_buffer[(y * SCREEN_WIDTH) + x] = color;
}


void Screen::Speed(int start) {
	int interval = start - LastTick;
	if (1000 / FPS > SDL_GetTicks() - start)
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
}

void Screen::Update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}


Screen::~Screen() {
	if (m_Initialize) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		std::cout << "Screen class destroyed" << std::endl;
	}
}
#ifndef SCREEN
#define SCREEN

#include<iostream>
#include<SDL.h>
#include"Global.h"


class Screen {
public:
	const static int SCREEN_WIDTH = 627;
	const static int SCREEN_HEIGHT = 605;
	static int FPS;


public:
	Screen(Uint32* buffer);
	~Screen();
	bool Initialize();
	void Update();
	void Speed(int start);

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer;
	bool m_Initialize;
	double SpeedV;
	int LastTick;

private:
	void Frame();
	void SetPixel(int x, int y, Uint32 color);

};
#endif

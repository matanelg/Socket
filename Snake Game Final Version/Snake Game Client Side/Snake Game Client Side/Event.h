#ifndef EVENT
#define EVENT
#include<SDL.h>
#include"Global.h"
#include"Screen.h"
#endif

class Event {
public:
	void ProcessEvents(Direction& direction);
};

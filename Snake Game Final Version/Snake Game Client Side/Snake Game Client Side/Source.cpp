#include<SDL.h>
#include<Socket.h>
#include<stdlib.h>
#include<time.h>
#include"Global.h"
#include"Screen.h""
#include"Food.h"
#include"Snake.h"
#include"Event.h"
#include"Package.h"
using namespace soc;

int Screen::FPS = 10;	 // Initialize renderer spped.
int Snake::Blocks = 5;	// Initialize snake size.

Uint32* buffer = new Uint32[Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT];  // Create buffer on heap for storing pixels.
Direction direction = Direction::UP;  // Create enum object for snake direction.
Uint32 start;

int main(int argc, char* argv[]) {

	int port; std::string ip;
	
	cout << "Please input your server local ip address(ipv4) = "; std::cin >> ip; // User input his ip address.
	
	cout << "Please input your port = "; std::cin >> port; // User input his port.
	
	Client client(ip, port); // Using our Socket static library. in this case for connect to server.

	Screen screen(buffer); // Initialize & Use Screen Object.

	srand(time(NULL)); // Generate a new sequence for food coordinate.

	if (screen.Initialize()) // Check initialization of screen object.
	{
		Food food(buffer);
		Snake snake(buffer);
		Event event;
		Package package;

		while (direction != Direction::EXIT) // Checking if the user is not close the window.
		{
			start = SDL_GetTicks(); // Get the time pass in mili-seconf from initialization sdl.

			if (food.SetFood(snake.getarrx(), snake.getarry())) // Check if snake eat his food and in that case increase his size.
				Snake::Blocks++;

			event.ProcessEvents(direction); // Check event.

			snake.KeepMoving(direction); // snake keep moving on screen. 

			if (snake.GameOver()) // Check if the snake not going out of the frame.
				break;

			client.Send(package.getPack(food.getx(), food.gety(), snake.getarrx(), snake.getarry())); // Send package to the server.

			screen.Speed(start); // Update speed.

			screen.Update(); // Update screen.

		}

	}
	delete[] buffer; // delete memory from heap.

	return 0;
}
#include<iostream>
#include<SDL.h>
#include<Socket.h>
#include"Screen.h"
#include"Event.h"
#include"Package.h"
#include"Global.h"
using namespace soc;

Uint32* buffer = new Uint32[Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT]; // Create buffer on heap for storing pixels.

int main(int argc, char* argv[]) {
	
	int port; std::string ip;
	
	cout << "Please input your server local ip address(ipv4) = "; std::cin >> ip; // User input his ip address.
	
	cout << "Please input your port = "; std::cin >> port; // User input his port.
	
	Server server(ip,port); // Using our Socket static library. in this case for listening to connection.
	
	Screen screen(buffer); // Initialize & Use Screen Object.
	
	Package package(buffer); // Initialize & Use Package Object.
	
	Event event; // Initialize & Use Event Object.

	if (screen.Initialize()) // Check initialization of screen object. 
	{

		while (event.ProcessEvents()) // Check Event.
		{
			int* data = server.Recive(); // Store the reciving data.

			if (data[0] == 0) // If reciving 0 its mean that client disconnect.
				break;

			package.SetData(data, WHITE); // Set pixels on screen.

			screen.Update(); // Update screen.

			package.SetData(data, BLACK); // delete old pixels in screen. 

		}
	}
	delete[] buffer; // Clean memory from heap.
	return 0;
}
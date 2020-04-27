#include"Package.h"


Package::Package(Uint32* buffer) {
	this->buffer = buffer;
}

void Package::SetBlock(int x, int y, Uint32 color) { // Draw block on screen.
	for (int col = -int(block_size / 2); col <= int(block_size / 2); col++) {
		for (int row = -int(block_size / 2); row <= int(block_size / 2); row++) {
			buffer[((y + row) * Screen::SCREEN_WIDTH) + (x + col)] = color;
		}
	}
}

void Package::SetData(int* data, Uint32 color) { // Recive and Draw data on screen.
	if (data[0] > Screen::SCREEN_WIDTH)
		SetBlock(data[0], data[1] - 1, RED); // Draw food.

	int blocks = *(data + 2);

	for (int i = 3; i < 3 + blocks; i++) {
		if (data[i] > Screen::SCREEN_WIDTH)
			SetBlock(data[i] - Screen::SCREEN_WIDTH, *(data + i + blocks), color); // Draw snake.
	}
}

Package::~Package() {
	std::cout << "Snake class destroyed" << std::endl;
}
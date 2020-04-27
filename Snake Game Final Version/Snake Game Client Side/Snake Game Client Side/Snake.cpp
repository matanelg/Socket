#include"Snake.h"


Snake::Snake(Uint32* buffer) {
	this->buffer = buffer;
	arrx = new int[Screen::SCREEN_WIDTH];
	arry = new int[Screen::SCREEN_HEIGHT];
	InitializeSnake();
}

void Snake::InitializeSnake() {
	for (int i = 0; i < Blocks; i++) {
		arrx[i] = Screen::SCREEN_WIDTH / 2;
		arry[i] = Screen::SCREEN_HEIGHT - (17) - block_size * ((Blocks - 1) - i);
		SetBlock(arrx[i], arry[i], WHITE);
	}
}

void Snake::SetBlock(int x, int y, Uint32 color) {
	for (int col = -block_size / 2; col <= block_size / 2; col++) {
		for (int row = -block_size / 2; row <= block_size / 2; row++) {
			buffer[((y + row) * Screen::SCREEN_WIDTH) + (x + col)] = color;
		}
	}
}


void Snake::RefreshArray(int x, int y) {
	for (int i = Blocks; i > 0; i--) {
		arrx[i] = arrx[i - 1];
		arry[i] = arry[i - 1];
	}
	arrx[0] += x; arry[0] += y;
}


void Snake::NewPosition(int x, int y) {
	for (int i = 0; i < Blocks; i++) {
		if (arrx[i] < Screen::SCREEN_WIDTH)
			SetBlock(arrx[i], arry[i], BLACK);
	}

	RefreshArray(x, y);

	for (int i = 0; i < Blocks; i++) {
		if (arrx[i] < Screen::SCREEN_WIDTH)
			SetBlock(arrx[i], arry[i], WHITE);
	}
};


void Snake::KeepMoving(Direction direction) {
	switch (direction) {
	case Direction::UP:
		NewPosition(0, -11);
		break;
	case Direction::DOWN:
		NewPosition(0, 11);
		break;
	case Direction::RIGHT:
		NewPosition(11, 0);
		break;
	case Direction::LEFT:
		NewPosition(-11, 0);
		break;
	default:
		break;
	}
}

bool Snake::GameOver() {
	if (arrx[0] < int(1.5 * block_size) || //
		arrx[0]>Screen::SCREEN_WIDTH * 2 - int(1.5 * block_size) ||
		arry[0] < int(1.5 * block_size) ||
		arry[0]>Screen::SCREEN_HEIGHT - int(1.5 * block_size))
	{
		std::cout << "Game Over" << std::endl;
		return true;
	}
	return false;
}

Snake::~Snake() {
	delete[] arry;
	delete[] arrx;
	std::cout << "Snake class destroyed" << std::endl;
}
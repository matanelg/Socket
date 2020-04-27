#include"Food.h"


Food::Food(Uint32* buffer) :Food_x(346), Food_y(346) {
	this->buffer = buffer;
	SetBlock(Food_x, Food_y, RED);
}

void Food::GetRandomPosition() {
	Food_x = 5 + 11 + 11 * (rand() % (112));
	Food_y = 5 + 11 + 11 * (rand() % (53));
}

bool Food::CheckSnakePosition(int* const arrx, int* const arry) {
	for (int i = 1; i < Snake::Blocks; i++) {
		if (arrx[i] == Food_x && arry[i] == Food_y) return false;
	}
	return true;
}


void Food::SetBlock(int x, int y, Uint32 color) {
	for (int col = -block_size / 2; col <= block_size / 2; col++) {
		for (int row = -block_size / 2; row <= block_size / 2; row++) {
			buffer[((y + row) * Screen::SCREEN_WIDTH) + (x + col)] = color;
		}
	}
}

bool Food::SetFood(int* const arrx, int* const arry) {
	if (*arrx == Food_x && *arry == Food_y)
	{
		while (true) {
			GetRandomPosition();
			if (CheckSnakePosition(arrx, arry))
			{
				if (Food_x < Screen::SCREEN_WIDTH)
				{
					SetBlock(Food_x, Food_y, RED);
					return true;
				}
				else
					return true;
			}
			else
				continue;
		}
	}

	return false;
}
#include"Package.h"

Package::Package() {
	data = new int[1000];
}
Package::~Package() {
	delete[] data;
	std::cout << "Package class destroyed." << std::endl;
}
int* Package::getPack(const int& food_x, const int& food_y, int* snake_x, int* snake_y) {
	*data = food_x;
	*(data + 1) = food_y;
	data[2] = Snake::Blocks;
	for (int i = 3; i < 3 + Snake::Blocks; i++) {
		data[i] = snake_x[i - 3];
		data[i + Snake::Blocks] = snake_y[i - 3];
	}
	return data;
}
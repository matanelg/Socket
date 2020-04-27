#pragma once
#include"Snake.h"

class Package {
private:
	int* data;
public:
	Package();
	~Package();
	int* getPack(const int& food_x, const int& food_y, int* snake_x, int* snake_y);
};

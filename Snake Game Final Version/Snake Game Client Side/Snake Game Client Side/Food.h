#ifndef FOOD
#define FOOD
#include"Screen.h"
#include"Snake.h"
#endif

class  Food {
private:
	Uint32* buffer;
	int Food_x;
	int Food_y;

private:
	void SetBlock(int x, int y, Uint32 color);
	void GetRandomPosition();
	bool CheckSnakePosition(int* const arrx, int* const arry);

public:
	Food(Uint32* buffer);
	bool SetFood(int* const arrx, int* const arry);
	int getx()const { return Food_x; }
	int gety()const { return Food_y; }


};


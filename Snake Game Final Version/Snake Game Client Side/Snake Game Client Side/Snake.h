#pragma once
#include"Screen.h"
#include"Global.h"
class  Snake {
private:
	Uint32* buffer;
	int* arry;
	int* arrx;

private:
	void InitializeSnake();
	void SetBlock(int cor_x, int cor_y, Uint32 color);
	void RefreshArray(int x, int y);
	void NewPosition(int x, int y);

public:
	static int Blocks;
	Snake(Uint32* buffer);
	~Snake();
	bool GameOver();
	void KeepMoving(Direction direction);
	int* getarrx() const { return arrx; }
	int* getarry() const { return arry; }
};

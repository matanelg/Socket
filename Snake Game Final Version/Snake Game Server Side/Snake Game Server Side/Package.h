#include"Screen.h"
class  Package {
private:
	Uint32* buffer;

public:
	Package(Uint32* buffer);
	~Package();
	void SetBlock(int cor_x, int cor_y, Uint32 color);
	void SetData(int* data, Uint32 color);
};

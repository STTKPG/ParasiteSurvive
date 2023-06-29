#ifndef MOUSE_H
#define MOUSE_H
#include "../Vector.h"
class Mouse
{
public:
	static Mouse* Instance()
	{
		static Mouse instance;
		return &instance;
	}
public:
	~Mouse(){}
	
private:
	Mouse():
	ScreenSize_X(0),
	ScreenSize_Y(0)
	{}
	Mouse(Mouse& Ins) = delete;

public:
	bool GetMousePointerVec(Vector* mousevector);

private:
	int ScreenSize_X;
	int ScreenSize_Y;

};

#endif // !"MOUSE_H"

#ifndef MOUSE_H
#define MOUSE_H
#include "DxLib.h"

class Mouse
{
//public:
//	static Mouse* Instance()
//	{
//		static Mouse instance;
//		return &instance;
//	}
//public:
//	~Mouse(){}
//
//public:
//	
//private:
//	Mouse(){}
//	Mouse(Mouse& Ins) = delete;
public:
	static bool GetMousePointer(VECTOR* mousevector);

private:

};

#endif // !"MOUSE_H"

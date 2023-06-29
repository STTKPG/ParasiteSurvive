#include "Mouse.h"

bool Mouse::GetMousePointerVec(Vector *mousevector)
{
	int ScrSizX;
	int ScrSizY;
	int ColBitDep;
	GetScreenState(&ScrSizX, &ScrSizY, &ColBitDep);
	
	int XBuffer;
	int YBuffer;
	
	if (GetMousePoint(&XBuffer, &YBuffer) == -1)
	{
		return false;
	}

	float XBufferF = (XBuffer - (ScrSizX / 2));
	float YBufferF = (YBuffer - (ScrSizY / 2));
	mousevector->Vec = VGet(XBufferF, YBufferF, 0);
	SetMousePoint(320, 240);

	return true;
}

//((Testx - (x / 2)) / 10)* 1 / GetFPS()
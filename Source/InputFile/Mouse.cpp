#include "Mouse.h"

bool Mouse::GetMousePointerVec(VECTOR *mousevector)
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

	XBuffer = (XBuffer - (ScrSizX / 2));
	YBuffer = (YBuffer - (ScrSizY / 2));//マジックナンバーを後々修正加える事
	
	*mousevector = VGet(-XBuffer, -YBuffer, 0);
	SetMousePoint(320, 240);

	return true;
}

//((Testx - (x / 2)) / 10)* 1 / GetFPS()
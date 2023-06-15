#include "Mouse.h"

bool Mouse::GetMousePointerVec(VECTOR *mousevector)
{
	int XBuffer;
	int YBuffer;
	
	if (GetMousePoint(&XBuffer, &YBuffer) == -1)
	{
		return false;
	}

	XBuffer = (XBuffer - 320) / 10;
	YBuffer = (YBuffer - 240) / 10;//�}�W�b�N�i���o�[����X�C�������鎖
	
	*mousevector = VGet(-XBuffer, -YBuffer, 0);
	SetMousePoint(320, 240);

	return true;
}

//((Testx - (x / 2)) / 10)* 1 / GetFPS()
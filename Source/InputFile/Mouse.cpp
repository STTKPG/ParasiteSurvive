#include "Mouse.h"

bool Mouse::GetMousePointer(VECTOR *mousevector)
{
	int XBuffer;
	int YBuffer;
	
	if (GetMousePoint(&XBuffer, &YBuffer) == -1)
	{
		return false;
	}

	XBuffer = 320 - XBuffer;
	YBuffer = 240 - YBuffer;//マジックナンバーを後々修正加える事

	*mousevector = VGet(-XBuffer, -YBuffer, 0);
	SetMousePoint(320, 240);

	return true;
}
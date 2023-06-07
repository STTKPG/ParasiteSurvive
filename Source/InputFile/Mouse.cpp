#include "Mouse.h"

bool Mouse::GetMousePointer(VECTOR *mousevector)
{
	int XBuffer;
	int YBuffer;

	if (GetMousePoint(&XBuffer, &YBuffer) == -1)
	{
		return false;
	}

	XBuffer = 100 - XBuffer;
	YBuffer = 100 - YBuffer;

	*mousevector = VGet(-XBuffer, -YBuffer, 0);
	SetMousePoint(100, 100);
}
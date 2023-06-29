#include "Player.h"
#include "../Source/InputFile/Mouse.h"
#include "../Vector.h"

void Player::Update()
{
	Vector MouseVec(0,0,0);
	Mouse::Instance()->GetMousePointerVec(&MouseVec);
	
	DegreeY =+ MouseVec.Vec.x;
	DegreeXZ =+ MouseVec.Vec.y;
	if (DegreeY >= 360)
	{
		DegreeY = 0;
	}
	DegreeXZ = min(max(DegreeXZ, 90), 270);

	DegreeXZ = (DegreeXZ * 180 / DX_PI) * 1 / 10000;
	DegreeY = (DegreeY * 180 / DX_PI) * (1 /10000);

	Vector XZVec(sinf(DegreeY * (1 / 10000)),0,cosf(DegreeY * (1 / 10000)));
	Vector YVec = Vector(0, min(max(MouseVec.Vec.y, 180), 0),0);
	Rotate += XZVec;
	//MouseVec.Vec.x = (MouseVec.Vec.x * (180 / DX_PI)) * (1 / 100);
	//MouseVec.Vec.y = (MouseVec.Vec.y * (180 / DX_PI)) * (1 / 100);

	camera.SetCameraPositionAndRotate(Pos.Vec ,DegreeXZ, DegreeY);

	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Pos = Pos + XZVec;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Pos = Pos - XZVec;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		Pos.Vec.x -= Rotate.Vec.z;
		Pos.Vec.z += Rotate.Vec.x;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		Pos.Vec.x += Rotate.Vec.z;
		Pos.Vec.z -= Rotate.Vec.x;
	}

	
}
#include "Player.h"
#include "../Source/InputFile/Mouse.h"
#include "../Vector.h"

void Player::Update()
{
	Vector MouseVec(0,0,0);
	Mouse::Instance()->GetMousePointerVec(&MouseVec);
	
	DegreeY += MouseVec.Vec.x;
	DegreeXZ += MouseVec.Vec.y;
	if (DegreeY >= 360)
	{
		DegreeY = 0;
	}
	DegreeXZ = min(max(DegreeXZ, 90), 270);

	float RadXZ = (DegreeXZ * (DX_PI / 180));
	float RadY = (DegreeY * (DX_PI / 180));

	Vector XZVec(-sinf(-RadY),0,-cosf(-RadY));
	Vector YVec = Vector(0, RadXZ ,0);
	Rotate = XZVec;
	//MouseVec.Vec.x = (MouseVec.Vec.x * (180 / DX_PI)) * (1 / 100);
	//MouseVec.Vec.y = (MouseVec.Vec.y * (180 / DX_PI)) * (1 / 100);

	camera.SetCameraPositionAndRotate(Pos.Vec ,RadXZ, -RadY);

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
		Pos.Vec.x += Rotate.Vec.z;
		Pos.Vec.z -= Rotate.Vec.x;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		Pos.Vec.x -= Rotate.Vec.z;
		Pos.Vec.z += Rotate.Vec.x;
	}

	
}
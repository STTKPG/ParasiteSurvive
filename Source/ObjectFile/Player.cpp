#include "Player.h"
#include "../Source/InputFile/Mouse.h"
#include "../Vector.h"

void Player::Update()
{
	Vector MouseVec(0,0,0);
	Mouse::Instance()->GetMousePointerVec(&MouseVec);
	
	//MouseVec.Vec.x = (MouseVec.Vec.x * (180 / DX_PI)) * (1 / 100);
	//MouseVec.Vec.y = (MouseVec.Vec.y * (180 / DX_PI)) * (1 / 100);


	Rotate += MouseVec;

	VECTOR Vec;
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Pos = Pos + Rotate.Xvec();
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Pos = Pos - Rotate;
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
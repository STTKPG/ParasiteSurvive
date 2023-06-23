#include "Player.h"
#include "../Source/InputFile/Mouse.h"

void Player::Update()
{
	GetTargetRotate();
	PlayerRotate();

	VECTOR Vec;
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Pos =VAdd(Pos, Rotate);
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Pos = VSub(Pos, Rotate);
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		Pos.x -= Rotate.z;
		Pos.z += Rotate.x;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		Pos.x += Rotate.z;
		Pos.z -= Rotate.x;
	}

	
}
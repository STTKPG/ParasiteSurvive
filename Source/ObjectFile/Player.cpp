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

	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{

	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{

	}

	
}

void Player::Draw(int modeldata)
{

}

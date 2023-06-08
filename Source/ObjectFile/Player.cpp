#include "Player.h"
#include "../Source/InputFile/Mouse.h"

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Pos.z++;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Pos.z--;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		Pos.x++;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		Pos.x--;
	}

	
}

void Player::Draw()
{

}

void Player::PlayerVector()
{
	VECTOR MousePointer;
	Mouse::Instance()->GetMousePointer(&MousePointer);
	
	
}

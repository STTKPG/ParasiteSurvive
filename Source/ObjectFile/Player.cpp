#include "Player.h"
#include "../Source/InputFile/Mouse.h"
#include "../Vector.h"
#include "../Matrix.h"

void Player::Update()
{
	Vector ORotate(0,0,0);
	Vector MouseVec(0, 0, 0);
	Mouse::Instance()->GetMousePointerVec(&MouseVec);
	DegreeY += MouseVec.Vec.x / 10;
	if (DegreeY < 0)
	{
		DegreeY = 360;
	}
	else if (DegreeY > 360)
	{
		DegreeY = 0;
	}

	float Rad = DegreeY * DX_PI / 180;

	//Vector Vec(cosf(Rad), 0, sinf(Rad));
	Vector Vec(0, Rad, 0);
	Rotate = Vec;

	Current = Idle;

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		
	}
	if (Is_Hit == true)
	{
		Current = Idle;
		Pos = Vector(0, 0, 0);
		Is_Hit = false;
	}
	else if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Current = Walk;
		Pos += Vector(-sinf(Rad),0, -cosf(Rad));
	}	
	else if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Current = Walk;
		Pos -= Vector(-sinf(Rad), 0, -cosf(Rad));
	}
	
	if (Is_Interact == true)
	{
		
		Is_Interact = false;
	}
}

void Player::Draw(int modeldata)
{
	if (Current != Old)
	{
		MV1DetachAnim(modeldata, AttachIndex);
		switch (Current)
		{
		case Player::Walk:
			AttachIndex = MV1AttachAnim(modeldata, 13);
			break;
		case Player::Shoot:
			AttachIndex = MV1AttachAnim(modeldata, 4);
			break;
		case Player::Idle:
			AttachIndex = MV1AttachAnim(modeldata, 3);
			break;
		default:
			break;
		}
		AnimTotalTime = MV1GetAttachAnimTotalTime(modeldata,AttachIndex);
		PlayTime = 0;
		Old = Current;
	}
	
	MV1SetAttachAnimTime(modeldata, AttachIndex, PlayTime);
	MV1SetScale(modeldata, Scale.Vec);
	MV1SetRotationXYZ(modeldata, Rotate.Vec);
	MV1SetPosition(modeldata, Pos.Vec);
	MV1DrawModel(modeldata);

	PlayTime++;
	if (PlayTime >= AnimTotalTime)
	{
		PlayTime = 0;
	}
}
//Vector MouseVec(0, 0, 0);
//Mouse::Instance()->GetMousePointerVec(&MouseVec);
//
//DegreeY += MouseVec.Vec.x * 1 / 10;
//DegreeXZ += MouseVec.Vec.y * 1 / 10;
//if (DegreeY >= 360)
//{
//	DegreeY = 0;
//}
//DegreeXZ = min(max(DegreeXZ, 90), 270);
//
//float RadXZ = (DegreeXZ * (DX_PI / 180));
//float RadY = (DegreeY * (DX_PI / 180));
//
//Vector XZVec(-sinf(-RadY), 0, -cosf(-RadY));
//Vector YVec = Vector(0, RadXZ, 0);
//Rotate = XZVec;
////MouseVec.Vec.x = (MouseVec.Vec.x * (180 / DX_PI)) * (1 / 100);
////MouseVec.Vec.y = (MouseVec.Vec.y * (180 / DX_PI)) * (1 / 100);
//
//camera.SetCameraPositionAndRotate(Pos.Vec, RadXZ, -RadY);
//
//if (CheckHitKey(KEY_INPUT_W) == 1)
//{
//	Pos = Pos + XZVec;
//}
//if (CheckHitKey(KEY_INPUT_S) == 1)
//{
//	Pos = Pos - XZVec;
//}
//if (CheckHitKey(KEY_INPUT_A) == 1)
//{
//	Pos.Vec.x += Rotate.Vec.z;
//	Pos.Vec.z -= Rotate.Vec.x;
//}
//if (CheckHitKey(KEY_INPUT_D) == 1)
//{
//	Pos.Vec.x -= Rotate.Vec.z;
//	Pos.Vec.z += Rotate.Vec.x;
//}

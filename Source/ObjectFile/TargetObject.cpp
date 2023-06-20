#include "TargetObject.h"
#include "../InputFile/Mouse.h"
#include "ObjectManager.h"

void TargetObject::Update()
{
	VECTOR TargetVec = VGet(0, 0, 1);
	MATRIX RotaMatX;
	MATRIX RotaMatY;
	MATRIX RotaMat;
	VECTOR MousePointerVec;
	Mouse::Instance()->GetMousePointerVec(&MousePointerVec);
	
	//float Xrad = DX_PI_F / MousePointerVec.x;
	//float Yrad = DX_PI_F / MousePointerVec.y;
	MATRIX ScaMat = MGetScale(VGet(3, 3, 0));
	MATRIX MoveMat = MGetIdent();

	MoveMat = MGetTranslate(ObjectManager::Instance()->GetObjectPos(Player));
	RotaMatX = MGetRotX((MousePointerVec.y) * (DX_PI / 180));
  	RotaMatY = MGetRotY((MousePointerVec.x) * (DX_PI / 180));
	
	RotaMat = MMult(RotaMatX,RotaMatY);
	MATRIX Matrix = MMult( MoveMat, RotaMat);
	Pos = VTransform(Pos, Matrix);
}

//void TargetObject::Draw(int modeldata)
//{
//	MV1SetPosition(modeldata, Pos);
//	MV1DrawModel(modeldata);
//}
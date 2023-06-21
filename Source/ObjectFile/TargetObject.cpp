#include "TargetObject.h"
#include "../InputFile/Mouse.h"
#include "ObjectManager.h"
#include "../Matrix.h"

void TargetObject::Update()
{
	VECTOR TargetVec = VGet(0, 0, 1);
	//MATRIX RotaMatX;
	//MATRIX RotaMatY;
	Matrix RotaX;
	Matrix RotaY;
	VECTOR MousePointerVec;
	Mouse::Instance()->GetMousePointerVec(&MousePointerVec);
	
	//float Xrad = DX_PI_F / MousePointerVec.x;
	//float Yrad = DX_PI_F / MousePointerVec.y;
	MATRIX ScaMat = MGetScale(VGet(3, 3, 0));
	MATRIX MoveMat = MGetIdent();

	RotaX.RotateX((MousePointerVec.y) * (DX_PI / 180));
	RotaY.RotateY((MousePointerVec.x) * (DX_PI / 180));
	//RotaMatX = MGetRotX((MousePointerVec.y) * (DX_PI / 180));
  	//RotaMatY = MGetRotY((MousePointerVec.x) * (DX_PI / 180));
	Matrix Mat = RotaX * RotaY;
	//RotaMat = MMult(RotaMatX,RotaMatY);
	//MATRIX Matrix = MMult( MoveMat,);
	Pos = VAdd(Mat.Zvec(), ObjectManager::Instance()->GetObjectPos(ObjectBase::Player));
}

//void TargetObject::Draw(int modeldata)
//{
//	MV1SetPosition(modeldata, Pos);
//	MV1DrawModel(modeldata);
//}
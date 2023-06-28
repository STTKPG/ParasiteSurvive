#include "TargetObject.h"
#include "../InputFile/Mouse.h"
#include "ObjectManager.h"
#include "../Matrix.h"
#include "../Vector.h"
#include "../Quaternion.h" 

void TargetObject::Update()
{/*
	VECTOR TargetVec = VGet(0, 0, 1);
	VECTOR MousePointerVec;
	Matrix RotaX;
	Matrix RotaY;
	Matrix Move;
	Matrix Mat;

	Mouse::Instance()->GetMousePointerVec(&MousePointerVec);
	
	Move.Translate(ObjectManager::Instance()->GetObjectPos(Player));
	RotaX.RotateX((MousePointerVec.y) * (DX_PI / 180) * 0.1);
	RotaY.RotateY((MousePointerVec.x) * (DX_PI / 180) * 0.1);
	Mat = RotaY * RotaX;

	Rotate = VTransform(Rotate, Mat.Mat);
	
	Pos = VAdd(Rotate, ObjectManager::Instance()->GetObjectPos(Player));*/


}
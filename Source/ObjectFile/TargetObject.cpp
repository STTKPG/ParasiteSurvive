#include "TargetObject.h"
#include "../InputFile/Mouse.h"
#include "ObjectManager.h"

void TargetObject::Update()
{
	VECTOR TargetVec = VGet(0, 0, 1);
	MATRIX RotaMatX;
	MATRIX RotaMatY;
	MATRIX RotaMat;
	std::list<ObjectBase*> RequObject;
	VECTOR MousePointerVec;
	Mouse::Instance()->GetMousePointerVec(&MousePointerVec);
	RequObject = ObjectManager::Instance()->GetObjectDate(ObjectType::Player);

	//float Xrad = DX_PI_F / MousePointerVec.x;
	//float Yrad = DX_PI_F / MousePointerVec.y;
	MATRIX ScaMat = MGetScale(VGet(3, 3, 0));
	RotaMatX = MGetRotX((MousePointerVec.x) * (DX_PI / 180));
  	RotaMatY = MGetRotY((MousePointerVec.y) * (DX_PI / 180));
	
	RotaMat = MMult(RotaMatY, RotaMatX);
	Pos = VTransform(Pos, RotaMat);
}

//void TargetObject::Draw(int modeldata)
//{
//	MV1SetPosition(modeldata, Pos);
//	MV1DrawModel(modeldata);
//}
#include "TargetObject.h"
#include "../InputFile/Mouse.h"
#include "ObjectManager.h"

void TargetObject::Update()
{
	MATRIX RotaMatX;
	MATRIX RotaMatY;
	MATRIX RotaMat;
	std::list<ObjectBase*> RequObject;
	VECTOR MousePointerVec;
	Mouse::Instance()->GetMousePointerVec(&MousePointerVec);
	RequObject = ObjectManager::Instance()->GetObjectDate(ObjectType::Player);
	float Xrad = DX_PI_F / MousePointerVec.x
	RotaMatX = MGetRotX();
	RotaMatY = MGetRotY(DX_PI_F / MousePointerVec.x);
	RotaMat = MMult(RotaMatX,RotaMatY);
	
	Pos = VTransform(Pos, RotaMatY);

}

//void TargetObject::Draw(int modeldata)
//{
//	MV1SetPosition(modeldata, Pos);
//	MV1DrawModel(modeldata);
//}
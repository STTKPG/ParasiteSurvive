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
	
	RotaMatX = MGetRotX(MousePointerVec.y);
	RotaMatY = MGetRotY(MousePointerVec.x);
	RotaMat = MMult(RotaMatX,RotaMatY);
	
	Pos = VTransform(Pos, RotaMat);

}

void TargetObject::Draw(int modeldata)
{
	MV1SetPosition(modeldata, Pos);
	MV1DrawModel(modeldata);
}
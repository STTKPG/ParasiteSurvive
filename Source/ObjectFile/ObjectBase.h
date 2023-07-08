#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "../Vector.h"

class ObjectBase
{
public:
	enum ObjectType
	{
		Player,
		Enemy,
		Floor,
		Barrel,
		Target,
		Wall,
		WallDoor,
		Door,
		Arch
	};
public:
	ObjectBase(ObjectType type,Vector pos = Vector(0,0,0), Vector rotate = Vector(0, 0, 0),Vector scale = Vector(1,1,1)) :
	Pos(pos),
	Rotate(rotate),
	Scale(scale),
	Is_Alive(true),
	Type(type),
	CameraDirection(0){}
	virtual ~ObjectBase() {}

public:
	virtual void Update() = 0;
	virtual void Draw(int modeldata)
	{
		MV1SetScale(modeldata,Scale.Vec);
		MV1SetRotationXYZ(modeldata, Rotate.Vec);
		MV1SetPosition(modeldata, Pos.Vec);
		MV1DrawModel(modeldata);
	}

public:
	Vector Pos;
	Vector Rotate;
	Vector Scale;
	ObjectType Type;
	float CameraDirection;
	bool Is_Alive;
	int Hp;

};

#endif
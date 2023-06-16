#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "DxLib.h"

class ObjectBase
{
public:
	enum ObjectType
	{
		Player,
		Enemy,
		Entity,
		Test,
		Barrel
	};
public:
	ObjectBase(ObjectType type,VECTOR pos = VGet(0, 0, 0),VECTOR rotate = VGet(0,0,0)):
	Pos(pos),
	Rotate(rotate),
	Is_Alive(false),
	Type(type){}
	~ObjectBase() {}

public:
	virtual void Update() = 0;
	virtual void Draw(int modeldata)
	{
		MV1SetPosition(modeldata, Pos);
		MV1DrawModel(modeldata);
	}

public:
	VECTOR Pos;
	VECTOR Rotate;
	ObjectType Type;
	bool Is_Alive;
	int Hp;

};

#endif
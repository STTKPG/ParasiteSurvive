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
		Test
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
	virtual void Draw(int modeldata) = 0;

public:
	VECTOR Pos;
	VECTOR Rotate;
	ObjectType Type;
	bool Is_Alive;
	int Hp;

};

#endif
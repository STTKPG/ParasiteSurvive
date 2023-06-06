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
		Entity
	};
public:
	ObjectBase(ObjectType type,VECTOR pos = VGet(0, 0, 0)):
	Pos(pos),
	Is_Alive(false),
	Type(type){}
	~ObjectBase() {}

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

public:
	VECTOR Pos;
	ObjectType Type;
	bool Is_Alive;
	int Hp;

};

#endif
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
		Target
	};
public:
	ObjectBase(ObjectType type,bool is_draw,Vector pos = Vector(0,0,0), Vector rotate = Vector(0, 0, 0)) :
	Pos(pos),
	Rotate(rotate),
	Is_Alive(true),
	Is_Draw(is_draw),
	Type(type){}
	~ObjectBase() {}

public:
	virtual void Update() = 0;
	virtual void Draw(int modeldata)
	{
		MV1SetPosition(modeldata, Pos.Vec);
		MV1DrawModel(modeldata);
	}

public:
	Vector Pos;
	Vector Rotate;
	ObjectType Type;
	bool Is_Alive;
	bool Is_Draw;
	int Hp;

};

#endif
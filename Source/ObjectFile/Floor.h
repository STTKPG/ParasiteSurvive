#ifndef FLOOR_H
#define FLOOR_H

#include "ObjectBase.h"

class Floor : public ObjectBase
{
public:
	Floor(ObjectType type,bool is_draw, Vector pos) :ObjectBase(type,is_draw, pos)
	{

	}
	~Floor(){}

public:
	void Update()override;
};

#endif // !FLOOR_H

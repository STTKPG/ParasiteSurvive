#ifndef FLOOR_H
#define FLOOR_H

#include "ObjectBase.h"

class Floor : public ObjectBase
{
public:
	Floor(ObjectType type,bool is_draw, Vector pos,Vector rotate) :ObjectBase(type,is_draw, pos,rotate)
	{
		
	}
	~Floor(){}

public:
	void Update()override;
	void Collision();

};

#endif // !FLOOR_H

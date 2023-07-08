#ifndef FLOOR_H
#define FLOOR_H

#include "ObjectBase.h"

class Floor : public ObjectBase
{
public:
	Floor(ObjectType type,Vector pos,Vector rotate, Vector scale) :ObjectBase(type,pos,rotate,scale)
	{
		
	}
	~Floor(){}

public:
	void Update()override;
	void Collision();

};

#endif // !FLOOR_H

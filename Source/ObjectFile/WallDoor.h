#ifndef WALLDOOR_H
#define WALLDOOR_H

#include "ObjectBase.h"

class WallDoor : public ObjectBase
{
public:
	WallDoor(ObjectType type, Vector pos, Vector rotate, Vector scale) :ObjectBase(type, pos, rotate, scale) {}
	~WallDoor(){}

private:
	void Update(){}

};

#endif // !WALLDOOR_H

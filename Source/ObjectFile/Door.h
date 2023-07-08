#ifndef DOOR_H
#define DOOR_H

#include "ObjectBase.h"

class Door : public ObjectBase
{
public:
	Door(ObjectType type, Vector pos, Vector rotate) :ObjectBase(type, pos, rotate) {}
	~Door(){}

protected:
	void Update(){}
};

#endif // !DOOR_H

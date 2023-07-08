#ifndef WALL_H
#define WALL_H

#include "ObjectBase.h"

class Wall : public ObjectBase
{
public:
	Wall(ObjectType type,Vector pos,Vector rotate,Vector scale) :ObjectBase(type,pos,rotate,scale){}
	~Wall(){}

protected:
	void Update()
	{

	}

};

#endif // !WALL_H

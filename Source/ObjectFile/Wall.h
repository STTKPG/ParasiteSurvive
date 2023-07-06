#ifndef WALL_H
#define WALL_H

#include "ObjectBase.h"

class Wall : public ObjectBase
{
public:
	Wall(ObjectType type, bool is_draw, Vector pos,Vector rotate) :ObjectBase(type, is_draw, pos,rotate){}
	~Wall(){}

protected:
	void Update(){}

};

#endif // !WALL_H

#ifndef BARREL_H
#define BARREL_H

#include "ObjectBase.h"

class Barrel : public ObjectBase
{
public:
	Barrel(ObjectBase::ObjectType type,bool is_draw, Vector pos) :ObjectBase(type,is_draw, pos)
	{

	}
	~Barrel(){}

private:
	void Update();
	void Draw();
};

#endif // !BARREL_H

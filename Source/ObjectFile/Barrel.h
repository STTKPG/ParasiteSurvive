#ifndef BARREL_H
#define BARREL_H

#include "ObjectBase.h"

class Barrel : public ObjectBase
{
public:
	Barrel(ObjectBase::ObjectType type,Vector pos) :ObjectBase(type, pos)
	{

	}
	~Barrel(){}

private:
	void Update();
	void Draw();
};

#endif // !BARREL_H

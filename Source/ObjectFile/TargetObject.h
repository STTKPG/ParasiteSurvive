#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	TargetObject(ObjectType type,VECTOR pos) :ObjectBase(type,pos)
	{

	}
	~TargetObject() {}

	void Update();
	//void Draw(int modeldata);

private:
	
};

#endif // !TARGETOBJECT_H
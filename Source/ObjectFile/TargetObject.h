#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	TargetObject(ObjectType type,Vector pos,Vector rotate) :ObjectBase(type,pos,rotate)
	{

	}
	~TargetObject() {}

	void Update();

private:
	VECTOR OldPlayerPos;
};

#endif // !TARGETOBJECT_H
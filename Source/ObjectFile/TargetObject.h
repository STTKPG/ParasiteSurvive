#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	TargetObject(ObjectType type,bool is_draw,VECTOR pos = VGet(0,0,1),VECTOR rotate = VGet(0,0,1)) :ObjectBase(type,is_draw,pos,rotate)
	{

	}
	~TargetObject() {}

	void Update();
};

#endif // !TARGETOBJECT_H
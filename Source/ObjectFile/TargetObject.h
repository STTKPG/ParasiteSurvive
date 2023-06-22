#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	TargetObject(ObjectType type,VECTOR pos = VGet(0,0,1),VECTOR rotate = VGet(0,0,1)) :ObjectBase(type,pos,rotate)
	{

	}
	~TargetObject() {}

	void Update();
	//void Draw(int modeldata);

	
};

#endif // !TARGETOBJECT_H
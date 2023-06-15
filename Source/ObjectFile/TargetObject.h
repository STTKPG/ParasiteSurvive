#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	TargetObject(ObjectType type) :ObjectBase(type,VGet(200,0,0))
	{

	}
	~TargetObject() {}

	void Update();
	void Draw(int modeldata);

private:
	
};

#endif // !TARGETOBJECT_H
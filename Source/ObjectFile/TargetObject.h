#ifndef TARGETOBJECT_H
#define TARGETOBJECT_H

#include "ObjectBase.h"

class TargetObject : public ObjectBase
{
public:
	~TargetObject() {}

	void Update();
	void Draw();
};

#endif // !TARGETOBJECT_H
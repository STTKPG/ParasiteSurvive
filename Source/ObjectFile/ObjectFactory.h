#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType Type);
};



#endif // !OBJECTFACTORY_H

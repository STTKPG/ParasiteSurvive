#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType Type)
	{
		switch (Type)
		{
		case ObjectBase::Player:
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Entity:
			break;
		default:
			break;
		}
	}
};



#endif // !OBJECTFACTORY_H

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"
#include "Player.h"
#include "TargetObject.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType type)
	{
		switch (type)
		{
		case ObjectBase::Player:
			return new Player(type);
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Entity:
			break;
		case ObjectBase::Target:
			return new TargetObject(type,VGet(0,0,1));
		default:
			break;
		}
	}
};



#endif // !OBJECTFACTORY_H

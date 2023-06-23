#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"
#include "Player.h"
#include "TargetObject.h"
#include "Floor.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType type,VECTOR pos)
	{
		switch (type)
		{
		case ObjectBase::Player:
			return new Player(type,false);
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Floor:
			return new Floor(type, true, VGet(0, 0, 0));
			break;
		case ObjectBase::Target:
			return new TargetObject(type,false,VGet(0,0,1));
		default:
			break;
		}
	}
};



#endif // !OBJECTFACTORY_H

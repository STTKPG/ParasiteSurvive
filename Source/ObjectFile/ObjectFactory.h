#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"
#include "Player.h"
#include "TargetObject.h"
#include "Floor.h"
#include "Wall.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType type,Vector pos,Vector rotate = Vector(0,0,0))
	{
		switch (type)
		{
		case ObjectBase::Player:
			return new Player(type,true,pos);
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Floor:
			return new Floor(type, true, pos, rotate);
			break;
		case ObjectBase::Wall:
			return new Wall(type,true,pos, rotate);

		case ObjectBase::Target:
			return new TargetObject(type,false,Vector(0,0,0),Vector(0,0,0));
		default:
			break;
		}
	}
};



#endif // !OBJECTFACTORY_H

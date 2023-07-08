#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"
#include "Player.h"
#include "TargetObject.h"
#include "Floor.h"
#include "Wall.h"
#include "WallDoor.h"
#include "Door.h"
#include "Arch.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType type,Vector pos,Vector rotate = Vector(0,0,0),Vector scale = Vector(1,1,1))
	{
		switch (type)
		{
		case ObjectBase::Player:
			return new Player(type,pos);
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Floor:
			return new Floor(type,pos,rotate,scale);
			break;
		case ObjectBase::Wall:
			return new Wall(type,pos, rotate,scale);
			break;
		case ObjectBase::Target:
			return new TargetObject(type,Vector(0,0,0),Vector(0,0,0));
			break;
		case ObjectBase::WallDoor:
			return new WallDoor(type, pos, rotate,scale);
			break;
		case ObjectBase::Door:
			return new Door(type, pos, rotate);
			break;
		case ObjectBase::Arch:
			return new Arch(type, pos, rotate,scale);
		default:
			break;
		}
	}
};



#endif // !OBJECTFACTORY_H

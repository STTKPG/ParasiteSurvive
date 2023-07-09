#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "ObjectBase.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "WallDoor.h"
#include "Door.h"
#include "Arch.h"
#include "BookCase.h"

class ObjectFactory
{
public:
	static ObjectBase* Create(ObjectBase::ObjectType type, SceneBase::SceneKind scene,Vector pos, std::string message = "", Vector rotate = Vector(0, 0, 0), Vector scale = Vector(1, 1, 1))
	{
		switch (type)
		{
		case ObjectBase::Player:
			return new Player(type,scene,pos,rotate,scale);
			break;
		case ObjectBase::Enemy:
			break;
		case ObjectBase::Floor:
			return new Floor(type,pos,rotate,scale);
			break;
		case ObjectBase::Wall:
			return new Wall(type,pos, rotate,scale);
			break;
		case ObjectBase::WallDoor:
			return new WallDoor(type, pos, rotate,scale);
			break;
		case ObjectBase::Door:
			return new Door(type, pos, rotate,scale,scene);
			break;
		case ObjectBase::Arch:
			return new Arch(type, pos, rotate,scale);
			break;
		case ObjectBase::BookCase:
			return new BookCase(type,message, pos, rotate, scale);
			break;
		default:
			return nullptr;
			break;
		}

		return nullptr;
	}
};



#endif // !OBJECTFACTORY_H

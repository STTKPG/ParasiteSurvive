#ifndef DOOR_H
#define DOOR_H

#include "ObjectBase.h"

class Door : public ObjectBase
{
public:
	Door(ObjectType type, Vector pos, Vector rotate, Vector scale, SceneBase::SceneKind scene,Vector size = Vector(200,0,200)) :ObjectBase(type,scene, pos, rotate, scale,size){}
	~Door(){}

protected:
	void Update(){}
};

#endif // !DOOR_H

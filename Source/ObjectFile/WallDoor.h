#ifndef WALLDOOR_H
#define WALLDOOR_H

#include "ObjectBase.h"

class WallDoor : public ObjectBase
{
public:
	WallDoor(ObjectType type, Vector pos, Vector rotate, Vector scale,Vector size = Vector(400,0,70),SceneBase::SceneKind scene = SceneBase::SceneKind::OverScene) :ObjectBase(type,scene, pos, rotate, scale,size) {}
	~WallDoor(){}

private:
	void Update(){}

};

#endif // !WALLDOOR_H

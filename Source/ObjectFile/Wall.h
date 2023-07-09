#ifndef WALL_H
#define WALL_H

#include "ObjectBase.h"

class Wall : public ObjectBase
{
public:
	Wall(ObjectType type,Vector pos,Vector rotate,Vector scale,Vector size = Vector(200,0,70),SceneBase::SceneKind scene = SceneBase::SceneKind::OverScene) :ObjectBase(type,scene,pos,rotate,scale,size){}
	~Wall(){}

protected:
	void Update()
	{

	}

};

#endif // !WALL_H

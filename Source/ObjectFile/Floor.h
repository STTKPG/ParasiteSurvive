#ifndef FLOOR_H
#define FLOOR_H

#include "ObjectBase.h"

class Floor : public ObjectBase
{
public:
	Floor(ObjectType type,Vector pos,Vector rotate, Vector scale,SceneBase::SceneKind scene = SceneBase::SceneKind::OverScene) :ObjectBase(type,scene,pos,rotate,scale)
	{
		
	}
	~Floor(){}

public:
	void Update()override;


};

#endif // !FLOOR_H

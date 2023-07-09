#ifndef BOOKCASE_H
#define BOOKCASE_H

#include "ObjectBase.h"

class BookCase : public ObjectBase
{
public:
	BookCase(ObjectType type,std::string message, Vector pos, Vector rotate, Vector scale, SceneBase::SceneKind scene = SceneBase::SceneKind::OverScene, Vector size = Vector(200, 0, 200)) :ObjectBase(type, scene, pos, rotate, scale, size,message)
	{

	}
	~BookCase(){}
protected:
	void Update()override{}

};

#endif // !BOOKCASE_H

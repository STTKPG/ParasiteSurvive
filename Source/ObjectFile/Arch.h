#ifndef ARCH_H
#define ARCH_H

#include "ObjectBase.h"

class Arch : public ObjectBase
{
public:
	Arch(ObjectType type, Vector pos, Vector rotate, Vector scale,SceneBase::SceneKind scene = SceneBase::SceneKind::OverScene) :ObjectBase(type,scene, pos, rotate, scale) {}
	~Arch(){}

private:
	void Update() {}
};

#endif // !ARCH_H

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "SceneBase.h"
#include "../ObjectFile/ObjectManager.h"

class MainScene : public SceneBase
{
public:
	MainScene()
	{
		ObjectManager::Instance()->EraseAll();
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 0),Vector(DX_PI,0,0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 0), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 200), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 200), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 400), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 400), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-100, 0, 0), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-100, 0, -100), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-100, 0, -200), Vector(DX_PI, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Player, Vector(0, -100, 0));
	}
	~MainScene(){}

protected:
	SceneKind Run();
	SceneKind Update();
	void Draw();
};

#endif // !MAINSCENE_H

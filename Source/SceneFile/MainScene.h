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
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 200));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 200));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 400));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, 400));
		ObjectManager::Instance()->Entry(ObjectBase::Player, Vector(0, 200, 0));
	}
	~MainScene(){}

protected:
	void Run();

private:

};

#endif // !MAINSCENE_H

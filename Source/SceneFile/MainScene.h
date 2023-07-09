#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "SceneBase.h"
#include "../ObjectFile/ObjectManager.h"
#include "../Camera.h"

class MainScene : public SceneBase
{
public:
	MainScene()
	{
		ObjectManager::Instance()->EraseAll();
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(0   , 0,    0), Vector(0,         0,0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(-200, 0,    0), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(0   , 0, -200), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(-200, 0, -200), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(0   , 0, -400), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor   , Vector(-200, 0, -400), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Player  , Vector(0   , 0,    0), Vector(0,         1, 0),Vector(1,1,1),SceneKind::MainScene);
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(100 , 0,    0), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(100 , 0, -200), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(100 , 0, -400), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(0   , 0,  100), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(-200, 0,  100), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(-300, 0,    0), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(-300, 0, -200), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall    , Vector(-300, 0, -400), Vector(0, -DX_PI / 2, 0));

		ObjectManager::Instance()->Entry(ObjectBase::Door    , Vector(-100, 0, -500), Vector(0,         0, 0),Vector(1,1,1),SceneKind::MainScene2);
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(-100, 0, -500), Vector(0,         0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Arch    , Vector(-100, 0, -500), Vector(0,         0, 0));
		camera = new Camera(Vector(0, 0, 0), Vector(0, 0, 0));
	}
	~MainScene()
	{
		delete camera;
		camera = nullptr;
		ObjectManager::Instance()->EraseAll();
	}

protected:
	SceneKind Update();
	void Draw();
	Camera* camera;
};

#endif // !MAINSCENE_H

#ifndef MAINSCENE2_H
#define MAINSCENE2_H

#include "SceneBase.h"
#include "../ObjectFile/ObjectManager.h"
#include "../Camera.h"

class MainScene2 : public SceneBase
{
public:
	MainScene2()
	{
		ObjectManager::Instance()->EraseAll();
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, 0), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, 0), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -200), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -200), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -800), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -800), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, -600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -800), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, -800), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -1000), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -1000), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -1200), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -1200), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -1400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -1400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-200, 0, -1600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(0, 0, -1600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -1400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, -1400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -1600), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(200, 0, -1600), Vector(0, 0, 0));
		//Player
		ObjectManager::Instance()->Entry(ObjectBase::Player, Vector(0, 0, -100), Vector(0, 1, 0),Vector(1,1,1),SceneKind::MainScene2);
		//•Ç
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, 0), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -200), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -400), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-300, 0, 0), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-300, 0, -200), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-300, 0, -400), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -500), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -900), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(200, 0, -500), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(200, 0, -900), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -1000), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -1200), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-300, 0, -1000), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-300, 0, -1200), Vector(0, -DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -1300), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -1700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(200, 0, -1300), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(200, 0, -1700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(0, 0, -1700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-200, 0, -1700), Vector(0, 0, 0));
		//ƒhƒA—Þ
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(-100, 0, 100), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door, Vector(-100, 0, 100), Vector(0, 0, 0),Vector(1,1,1),SceneKind::MainScene);
		ObjectManager::Instance()->Entry(ObjectBase::Arch, Vector(-100, 0, 100), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(300, 0, -700), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door    , Vector(300, 0, -700), Vector(0, DX_PI / 2, 0), Vector(1, 1, 1), SceneKind::MainScene3);
		ObjectManager::Instance()->Entry(ObjectBase::Arch    , Vector(300, 0, -700), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(-500, 0, -700), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door    , Vector(-500, 0, -700), Vector(0, DX_PI / 2, 0), Vector(1, 1, 1), SceneKind::MainScene4);
		ObjectManager::Instance()->Entry(ObjectBase::Arch    , Vector(-500, 0, -700), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(300, 0, -1500), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door, Vector(300, 0, -1500), Vector(0, DX_PI / 2, 0), Vector(1, 1, 1), SceneKind::MainScene);
		ObjectManager::Instance()->Entry(ObjectBase::Arch, Vector(300, 0, -1500), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(-500, 0, -1500), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door, Vector(-500, 0, -1500), Vector(0, DX_PI / 2, 0), Vector(1, 1, 1), SceneKind::MainScene);
		ObjectManager::Instance()->Entry(ObjectBase::Arch, Vector(-500, 0, -1500), Vector(0, DX_PI / 2, 0));

		
		camera = new Camera(Vector(0, 0, 0), Vector(0, 0, 0));
	}
	~MainScene2()
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

#endif // !MAINSCENE2_H

#ifndef MAINSCENE3_H
#define MAINSCENE3_H

#include "SceneBase.h"
#include "../ObjectFile/ObjectManager.h"
#include "../Camera.h"

class MainScene3 : public SceneBase
{
public:
	MainScene3()
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

		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, 0), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -200), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -400), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Floor, Vector(-400, 0, -600), Vector(0, 0, 0));
	
		//Player
		ObjectManager::Instance()->Entry(ObjectBase::Player, Vector(0, 0, -100), Vector(0, 1, 0), Vector(1, 1, 1), SceneKind::MainScene3);
		//•Ç
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, 0), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -200), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -400), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(100, 0, -600), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-500, 0, 0), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-500, 0, -200), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-500, 0, -400), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-500, 0, -600), Vector(0, DX_PI / 2, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(0, 0, -700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-200, 0, -700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -700), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, 100), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Wall, Vector(-400, 0, -230), Vector(0, 0, 0));

		//–{’I
		ObjectManager::Instance()->Entry(ObjectBase::BookCase, Vector(-400, 0, -650),Vector(0,0,0),Vector(1,1,1),SceneKind::OverScene,"ŽÀŒ±‹L˜^1");
		ObjectManager::Instance()->Entry(ObjectBase::BookCase, Vector(-400, 0, -300), Vector(0, 0, 0), Vector(1, 1, 1), SceneKind::OverScene, "ŽÀŒ±‹L˜^2");
		ObjectManager::Instance()->Entry(ObjectBase::BookCase, Vector(-450, 0, -50), Vector(0, DX_PI / 2, 0), Vector(1, 1, 1), SceneKind::OverScene, "”à‚Ì‘O‚ÅQ");
		
		//ƒhƒA—Þ
		ObjectManager::Instance()->Entry(ObjectBase::WallDoor, Vector(-100, 0, 100), Vector(0, 0, 0));
		ObjectManager::Instance()->Entry(ObjectBase::Door, Vector(-100, 0, 100), Vector(0, 0, 0), Vector(1, 1, 1), SceneKind::MainScene2);
		ObjectManager::Instance()->Entry(ObjectBase::Arch, Vector(-100, 0, 100), Vector(0, 0, 0));

		camera = new Camera(Vector(0, 0, 0), Vector(0, 0, 0));
	}
	~MainScene3()
	{

		delete camera;
		camera = nullptr;
		ObjectManager::Instance()->EraseAll();
	}

private:
	SceneKind Update();
	void Draw();
	Camera* camera;
};

#endif // !MAINSCENE3_H

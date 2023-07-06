#include "MainScene.h"
#include "../ObjectFile/Player.h"
void MainScene::Run()
{
	Player::Instance()->Update();
	ObjectManager::Instance()->Update();

	Player::Instance()->Draw();
	ObjectManager::Instance()->Draw();
}
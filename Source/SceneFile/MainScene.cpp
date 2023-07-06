#include "MainScene.h"
#include "../ObjectFile/Player.h"
SceneBase::SceneKind MainScene::Run()
{
	ObjectManager::Instance()->Update();

	ObjectManager::Instance()->Draw();

	return SceneKind::MainScene;
}

SceneBase::SceneKind MainScene::Update()
{
	ObjectManager::Instance()->Update();
	return SceneKind::MainScene;
}

void MainScene::Draw()
{
	ObjectManager::Instance()->Draw();
}
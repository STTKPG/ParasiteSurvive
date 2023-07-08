#include "MainScene.h"
#include "../ObjectFile/Player.h"
//SceneBase::SceneKind MainScene::Run()
//{
//	ObjectManager::Instance()->Update();
//
//	ObjectManager::Instance()->Draw();
//
//	return SceneKind::MainScene;
//}

SceneBase::SceneKind MainScene::Update()
{
	ObjectManager::Instance()->Update();
	camera->SetPositionAndTarget(ObjectManager::Instance()->PlayerRotate(), ObjectManager::Instance()->PlayerPos());
	return SceneKind::MainScene;
	return SceneKind::MainScene;
}

void MainScene::Draw()
{
	ObjectManager::Instance()->Draw(camera->GetPos());
}
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

	return ObjectManager::Instance()->PlayerScene();
}

void MainScene::Draw()
{
	ObjectManager::Instance()->Draw(camera->GetPos());
}
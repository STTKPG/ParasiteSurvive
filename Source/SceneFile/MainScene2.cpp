#include "MainScene2.h"

SceneBase::SceneKind MainScene2::Update()
{

	ObjectManager::Instance()->Update();
	camera->SetPositionAndTarget(ObjectManager::Instance()->PlayerRotate(), ObjectManager::Instance()->PlayerPos());

	return ObjectManager::Instance()->PlayerScene();
}

void MainScene2::Draw()
{
	ObjectManager::Instance()->Draw(camera->GetPos());
}
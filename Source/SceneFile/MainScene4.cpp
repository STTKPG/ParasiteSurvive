#include "MainScene4.h"

SceneBase::SceneKind MainScene4::Update()
{

	ObjectManager::Instance()->Update();
	camera->SetPositionAndTarget(ObjectManager::Instance()->PlayerRotate(), ObjectManager::Instance()->PlayerPos());

	return ObjectManager::Instance()->PlayerScene();
}

void MainScene4::Draw()
{
	ObjectManager::Instance()->Draw(camera->GetPos());
}
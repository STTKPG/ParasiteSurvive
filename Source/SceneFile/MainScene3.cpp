#include "MainScene3.h"

SceneBase::SceneKind MainScene3::Update()
{

	ObjectManager::Instance()->Update();
	camera->SetPositionAndTarget(ObjectManager::Instance()->PlayerRotate(), ObjectManager::Instance()->PlayerPos());

	return ObjectManager::Instance()->PlayerScene();
}

void MainScene3::Draw()
{
	ObjectManager::Instance()->Draw(camera->GetPos());
}
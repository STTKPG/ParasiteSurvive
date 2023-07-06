#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../ObjectFile/ObjectManager.h"
#include "SceneFactory.h"
class SceneManager
{

public:
	static SceneManager* Instance()
	{
		static SceneManager instance(SceneBase::SceneKind::OverScene,SceneBase::SceneKind::MainScene);
		return &instance;
	}

public:
	~SceneManager(){}
	void Run()
	{
		if (CurrentScene == nullptr)
		{
			CurrentScene = SceneFactory::CreateScene(NewSceneStep);
			ModelManager::Instance()->LoadModel(NewSceneStep);
		}

		NewSceneStep = CurrentScene->Update();

		CurrentScene->Draw();

		if (NewSceneStep != OldSceneStep)
		{
			delete CurrentScene;
			CurrentScene = nullptr;
		}
		OldSceneStep = NewSceneStep;
		
	} 


private:
	SceneManager(SceneBase::SceneKind oscene, SceneBase::SceneKind nscene) :
	OldSceneStep(oscene),
	NewSceneStep(nscene){}
	SceneManager(const SceneManager& Ins) = delete;

private:
	SceneBase* CurrentScene;
	SceneBase::SceneKind OldSceneStep;
	SceneBase::SceneKind NewSceneStep;
};

#endif // !SCENEMANAGER_H

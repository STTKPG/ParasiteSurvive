#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Common.h"
#include "../ObjectFile/ObjectManager.h"
#include "SceneBase.h"

class SceneManager
{

public:
	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}

public:
	~SceneManager(){}
	SceneBase::SceneKind Run()
	{
		return CurrentScene->Run();
	}


private:
	SceneManager(){}
	SceneManager(const SceneManager& Ins) = delete;

private:
	SceneBase* CurrentScene;

};

#endif // !SCENEMANAGER_H

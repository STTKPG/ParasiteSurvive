#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Common.h"
#include "../ObjectFile/ObjectManager.h"

class SceneManager
{
public:
	enum class SceneStep
	{
		Init,
		Main,
		Finish
	};

public:
	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}

public:
	~SceneManager(){}
	Scene::SceneKind Run();

private:
	SceneManager(){}
	SceneManager(const SceneManager& Ins) = delete;

private:
	SceneStep CurrentStep;

};

#endif // !SCENEMANAGER_H

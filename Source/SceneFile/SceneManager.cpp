#include "SceneManager.h"
#include "../ObjectFile/ObjectManager.h"

Scene::SceneKind SceneManager::Run()
{
	switch (CurrentStep)
	{
	case SceneManager::SceneStep::Init:
		break;
	case SceneManager::SceneStep::Main:

		break;
	case SceneManager::SceneStep::Finish:
		break;
	default:
		break;
	}

	return Scene::SceneKind::Test;
}
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
<<<<<<< HEAD

	return Scene::SceneKind::Test;
=======
>>>>>>> b887115ce6db1be974691ba5cfe31353631656af
}
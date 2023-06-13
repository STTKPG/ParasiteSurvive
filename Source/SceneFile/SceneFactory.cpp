#include "SceneFactory.h"

void SceneFactory::CreateScene(Scene::SceneKind next)
{
	switch (next)
	{
	case Scene::SceneKind::Title:

		break;
	case Scene::SceneKind::Main:
		break;
	case Scene::SceneKind::Over:
		break;
	case Scene::SceneKind::Clear:
		break;
	default:
		break;
	}
}
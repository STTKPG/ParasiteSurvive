#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "SceneBase.h"
#include "MainScene.h"
class SceneFactory
{
public:
	static SceneBase* CreateScene(SceneBase::SceneKind next)
	{
		switch (next)
		{
		case SceneBase::SceneKind::MainScene:
			return new MainScene;
			break;
		case SceneBase::SceneKind::OverScene:
			return nullptr;
			break;
		default:
			return nullptr;
			break;
		}
	}
};

#endif // !SCENEFACTORY_H
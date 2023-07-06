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
			new MainScene;
			break;
		case SceneBase::SceneKind::OverScene:
			break;
		default:
			break;
		}
	}
};

#endif // !SCENEFACTORY_H
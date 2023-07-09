#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "SceneBase.h"
#include "MainScene.h"
#include "MainScene2.h"
#include "MainScene3.h"
#include "MainScene4.h"
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
		case SceneBase::SceneKind::MainScene2:
			return new MainScene2;
			break;
		case SceneBase::SceneKind::MainScene3:
			return new MainScene3;
			break;
		case SceneBase::SceneKind::MainScene4:
			return new MainScene4;
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
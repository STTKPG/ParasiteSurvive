#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "../Common.h"

class SceneFactory
{
public:
	SceneFactory* Instance()
	{
		static SceneFactory instance;
		return &instance;
	}
	~SceneFactory() {}

public:
	void CreateScene(Scene::SceneKind next);
	void Run();
private:
	SceneFactory() {}
	SceneFactory(const SceneFactory& obj) {}
};

#endif // !SCENEFACTORY_H
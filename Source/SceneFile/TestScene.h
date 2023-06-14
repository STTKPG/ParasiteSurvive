#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "SceneBase.h"
#include "../ObjectFile/ModelManager.h"

class TestScene : public SceneBase
{
public:
	TestScene()
	{
		ModelManager::Instance()->LoadModel()
	}
	~TestScene(){}

protected:
	void Run();
};

#endif // !TESTSCENE_H

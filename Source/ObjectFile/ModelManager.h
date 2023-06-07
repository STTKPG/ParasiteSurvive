#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <string>
#include "..\Common.h"
class ModelManager
{
public:
	static ModelManager* Instance()
	{
		static ModelManager instance;
		return &instance;
	}
public:

	~ModelManager(){}

	void LoadModel(Scene::SceneKind Type);
	int SetModelData(std::string modelname);
	void Deletemodel(std::string modelname);
	void AllDeleteModel();

private:
	ModelManager() {}
	ModelManager(ModelManager& Ins) = delete;

private:
	std::map<std::string, int> ModelData;
};

#endif // !MODELMANAGER_H

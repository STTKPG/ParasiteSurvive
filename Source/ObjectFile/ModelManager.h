#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <string>
#include "..\Common.h"
class ModelManager
{
public:

	~ModelManager(){}

	void LoadModel(Scene::SceneKind Type);
	int SetModelData(std::string modelname);
	void Deletemodel(std::string modelname);
	void AllDeleteModel();

private:
	ModelManager() {}
	ModelManager(ModelManager& Obj) = delete;

private:
	std::map<std::string, int> ModelData;
};

#endif // !MODELMANAGER_H

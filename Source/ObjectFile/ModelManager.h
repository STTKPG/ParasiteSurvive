#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <string>
#include "..\Common.h"
#include "ObjectBase.h"
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
	int SetModelData(ObjectBase::ObjectType type);
	void Deletemodel(ObjectBase::ObjectType type);
	void AllDeleteModel();

private:
	ModelManager() {}
	ModelManager(ModelManager& Ins) = delete;

private:
	std::map<ObjectBase::ObjectType, int> ModelData;
};

#endif // !MODELMANAGER_H

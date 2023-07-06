#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <string>
#include "ObjectBase.h"
#include "../SceneFile/SceneBase.h"

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

	void LoadModel(SceneBase::SceneKind currentscene);
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

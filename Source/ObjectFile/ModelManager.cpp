#include "ModelManager.h"
#include "DxLib.h"

void ModelManager::LoadModel(Scene::SceneKind Type)
{
	switch (Type)
	{
	case Scene::SceneKind::Title:
		break;
	case Scene::SceneKind::Main:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Entity,MV1LoadModel("ModelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Entity,MV1LoadModel("modelData/Floor_Standard.mv1")));
		break;
	case Scene::SceneKind::Over:
		break;
	case Scene::SceneKind::Clear:
		break;
	case Scene::SceneKind::Test:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Test, MV1LoadModel("ModelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Entity, MV1LoadModel("modelData/Floor_Standard.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Barrel, MV1LoadModel("modelData/Barrel.mv1")));
		break;
	default:
		break;
	}
}

int ModelManager::SetModelData(ObjectBase::ObjectType type)
{
	auto Itr = ModelData.find(type);
	return (*Itr).second;
}

void ModelManager::Deletemodel(ObjectBase::ObjectType type)
{
	auto Itr = ModelData.find(type);
	MV1DeleteModel((*Itr).second);
	ModelData.erase(Itr);
}

void ModelManager::AllDeleteModel()
{
	for (auto itr = ModelData.begin();itr != ModelData.end();itr++)
	{
		MV1DeleteModel((*itr).second);
		ModelData.erase(itr);
	}

	ModelData.clear();
}
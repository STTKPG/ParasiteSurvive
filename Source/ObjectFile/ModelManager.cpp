#include "ModelManager.h"
#include "DxLib.h"

void ModelManager::LoadModel(Scene::SceneKind Type)
{
	switch (Type)
	{
	case Scene::SceneKind::Title:
		break;
	case Scene::SceneKind::Main:
		ModelData.insert(std::make_pair("WallStandardModel",MV1LoadModel("ModelData/Wall.mv1")));
		ModelData.insert(std::make_pair("FloorStandardModel",MV1LoadModel("modelData/Floor_Standard.mv1")));
		break;
	case Scene::SceneKind::Over:
		break;
	case Scene::SceneKind::Clear:
		break;
	case Scene::SceneKind::Test:
		ModelData.insert(std::make_pair("WallStandardModel", MV1LoadModel("ModelData/Wall.mv1")));
		ModelData.insert(std::make_pair("FloorStandardModel", MV1LoadModel("modelData/Floor_Standard.mv1")));
		break;
	default:
		break;
	}
}

int ModelManager::SetModelData(std::string modelname)
{
	auto Itr = ModelData.find(modelname);
	return (*Itr).second;
}

void ModelManager::Deletemodel(std::string modelname)
{
	auto Itr = ModelData.find(modelname);
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
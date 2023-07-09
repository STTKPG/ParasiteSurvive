#include "ModelManager.h"
#include "DxLib.h"

void ModelManager::LoadModel(SceneBase::SceneKind scene)
{
	switch (scene)
	{
	case SceneBase::SceneKind::MainScene:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Floor, MV1LoadModel("modelData/Floor_Standard.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Wall, MV1LoadModel("modelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::WallDoor, MV1LoadModel("modelData/Wall_Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Door, MV1LoadModel("modelData/Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Player, MV1LoadModel("modeldata/Player.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Arch, MV1LoadModel("modeldata/Arch.mv1")));
		break;
	case SceneBase::SceneKind::MainScene2:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Floor, MV1LoadModel("modelData/Floor_Standard.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Wall, MV1LoadModel("modelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::WallDoor, MV1LoadModel("modelData/Wall_Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Door, MV1LoadModel("modelData/Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Player, MV1LoadModel("modeldata/Player.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Arch, MV1LoadModel("modeldata/Arch.mv1")));
		break;
	case SceneBase::SceneKind::MainScene3:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Floor, MV1LoadModel("modelData/Floor_Standard.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Wall, MV1LoadModel("modelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::WallDoor, MV1LoadModel("modelData/Wall_Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Door, MV1LoadModel("modelData/Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Player, MV1LoadModel("modeldata/Player.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Arch, MV1LoadModel("modeldata/Arch.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::BookCase, MV1LoadModel("modeldata/Bookcase_Full.mv1")));
		break;
	case SceneBase::SceneKind::MainScene4:
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Floor, MV1LoadModel("modelData/Floor_Standard.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Wall, MV1LoadModel("modelData/Wall.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::WallDoor, MV1LoadModel("modelData/Wall_Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Door, MV1LoadModel("modelData/Door.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Player, MV1LoadModel("modeldata/Player.mv1")));
		ModelData.insert(std::make_pair(ObjectBase::ObjectType::Arch, MV1LoadModel("modeldata/Arch.mv1")));
		break;
	case SceneBase::SceneKind::OverScene:
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
	}

	ModelData.clear();
}


//ModelData.insert(std::make_pair(ObjectBase::ObjectType::Barrel, MV1LoadModel("modelData/Barrel.mv1")));
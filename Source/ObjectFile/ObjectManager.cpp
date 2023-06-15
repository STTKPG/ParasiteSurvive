#include "ObjectManager.h"
#include "ModelManager.h"

bool ObjectManager::Entry(ObjectBase* Obj)
{
	if (Obj == nullptr)
	{
		return false;
	}

	Objects.push_back(Obj);

	return true;
}

void ObjectManager::Update()
{
	for (ObjectBase* Obj : Objects)
	{
		if (Obj->Is_Alive == true)
		{
			Obj->Update();
		}
	}
}

void ObjectManager::Draw()
{
	for (ObjectBase* Obj : Objects)
	{
		if (Obj->Is_Alive == true)
		{
			Obj->Draw(ModelManager::Instance()->SetModelData(Obj->Type));
		}
	}
}

void ObjectManager::Erase()
{
	for (auto itr = Objects.begin(); itr != Objects.end();)
	{
		if ((*itr)->Is_Alive == false)
		{
			delete (*itr);
			*itr = nullptr;
			itr = Objects.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void ObjectManager::EraseAll()
{
	for (auto itr = Objects.begin(); itr != Objects.end();)
	{
		delete (*itr);
		*itr = nullptr;
		itr = Objects.erase(itr);
	}

	Objects.clear();

}

 std::list<ObjectBase*> ObjectManager::GetObjectDate(ObjectBase::ObjectType type)
{
	 std::list<ObjectBase*> RequObjList;
	for (auto itr = Objects.begin(); itr != Objects.end(); itr++)
	{
		if ((*itr)->Type == type)
		{
			RequObjList.push_back(*itr);
		}
	}

	return RequObjList;
}
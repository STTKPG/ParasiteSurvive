#include "ObjectManager.h"
#include "ModelManager.h"
#include "ObjectFactory.h"

bool ObjectManager::Entry(ObjectBase::ObjectType type,Vector pos,Vector rotate)
{
	ObjectBase* Obj = ObjectFactory::Create(type,pos,rotate);
	
	if (Obj->Type == ObjectBase::ObjectType::Player)
	{
		player = Obj;
	}

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

void ObjectManager::Draw(Vector camerapos)
{
	std::list<ObjectBase*> DrawList;

	for (ObjectBase* Obj : Objects)
	{
		Vector Length(0,0,0);

		Length = camerapos - Obj->Pos;

		Obj->CameraDirection = Length.Length();
		if (DrawList.size() == 0)
		{
			DrawList.push_back(Obj);
		}
		else
		{
			int Size = DrawList.size();
			for (auto itr = DrawList.begin(); itr != DrawList.end(); itr++)
			{
				if ((*itr)->CameraDirection <= Obj->CameraDirection)
				{
					DrawList.insert(itr, Obj);
					break;
				}
			}
			if (Size == DrawList.size())
			{
				DrawList.push_back(Obj);
			}
		}
	}

	std::list<ObjectBase*> ReverceDrawList;
	for (ObjectBase* DrawObj : DrawList)
	{
		if (DrawObj->Type == ObjectBase::Floor)
		{
			ReverceDrawList.push_front(DrawObj);
		}
		else
		{
			ReverceDrawList.push_back(DrawObj);
		}
	}
	
	for (ObjectBase* DrawObj : ReverceDrawList)
	{
			DrawObj->Draw(ModelManager::Instance()->SetModelData(DrawObj->Type));
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

 std::list<ObjectBase*> ObjectManager::GetObjectsDate(ObjectBase::ObjectType type)
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
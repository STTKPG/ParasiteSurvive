#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <list>
#include "ObjectBase.h"
#include "Player.h"

class ObjectManager
{
public:
	
	~ObjectManager(){}

public:
	static ObjectManager* Instance()
	{
		static ObjectManager instance;
		return &instance;
	}

public:
	bool Entry(ObjectBase::ObjectType type,Vector pos,Vector rotate = Vector(0,0,0));
	void Update();
	void Draw();
	void Erase();
	void EraseAll();
	std::list<ObjectBase*> GetObjectsDate(ObjectBase::ObjectType type);
 //�����̊֐��̗Z�ʂ������Ȃ�����̂ł������ǈĂ��o������
	Vector GetObjectPos(ObjectBase::ObjectType type) //�n���͓̂����^�C�v�̒��ň�ԍŏ��Ɍ����������̂̂�
	{
		for (auto Itr = Objects.begin();Itr != Objects.end();Itr++)
		{
			if ((*Itr)->Type == type)
			{
				return (*Itr)->Pos;
			}
		}

		return Vector(0,0,0);
	}

private:
	ObjectManager()
	{
		Objects.clear();
	}
	ObjectManager(ObjectManager& Ins) = delete;

private:
	std::list<ObjectBase*> Objects;
	ObjectBase* player;
};

#endif // !OBJECTMANAGER_H

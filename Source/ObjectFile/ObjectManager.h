#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <list>
#include "ObjectBase.h"

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
	bool Entry(ObjectBase::ObjectType type,VECTOR pos);
	void Update();
	void Draw();
	void Erase();
	void EraseAll();
	std::list<ObjectBase*> GetObjectsDate(ObjectBase::ObjectType type);
 //�����̊֐��̗Z�ʂ������Ȃ�����̂ł������ǈĂ��o������
	VECTOR GetObjectPos(ObjectBase::ObjectType type) //�n���͓̂����^�C�v�̒��ň�ԍŏ��Ɍ����������̂̂�
	{
		for (auto Itr = Objects.begin();Itr != Objects.end();Itr++)
		{
			if ((*Itr)->Type == type)
			{
				return (*Itr)->Pos;
			}
		}

		return VGet(0, 0, 0);
	}

private:
	ObjectManager()
	{
		Objects.clear();
	}
	ObjectManager(ObjectManager& Ins) = delete;

private:
	std::list<ObjectBase*> Objects;

};

#endif // !OBJECTMANAGER_H

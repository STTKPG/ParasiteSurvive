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
	bool Entry(ObjectBase* Obj);
	void Update();
	void Draw();
	void Erase();
	void EraseAll();

private:
	ObjectManager()
	{
		Objects.clear();
	}
	ObjectManager(ObjectManager& Obj) = delete;
private:
	std::list<ObjectBase*> Objects;

};

#endif // !OBJECTMANAGER_H

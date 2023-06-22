#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"
#include "ObjectManager.h"

class Player : public ObjectBase
{
public:
	Player(ObjectType type) : ObjectBase(type)
	{

	}
	~Player(){}

public:
	VECTOR GetRotate()
	{
		return Rotate;
	}
protected:
	void Draw(int modeldata)override;
	void Update()override;
	void GetTargetRotate()
	{
		std::list<ObjectBase*> Requ = ObjectManager::Instance()->GetObjectsDate(Target);

		for (auto Itr = Requ.begin(); Itr != Requ.end(); Itr++)
		{
			TargetRotate = (*Itr)->Rotate;
		}
	}
	void PlayerRotate()
	{
		this->Rotate.x = TargetRotate.x * 1;
		this->Rotate.y = TargetRotate.y * 0;
		this->Rotate.z = TargetRotate.z * 1;
	}

private:
	VECTOR TargetRotate;
};

#endif // !PLAYER_H

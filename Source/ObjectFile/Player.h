#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"
#include "ObjectManager.h"
#include "../Camera.h"

class Player : public ObjectBase
{
public:
	enum PlayerAction
	{
		Walk,
		Shoot,
		Idle
	};
public:
	Player(ObjectType type, Vector pos) : ObjectBase(type, pos)
		, DegreeY(180)
		, Current(Idle)
		,Old(Idle)
		,AnimTotalTime(0)
		,PlayTime(0)
		,AttachIndex(3)
	{

	}
	~Player(){}

	//Player(const Player& obj){}
public:
	Vector GetRotate()
	{
		return Rotate;
	}
	
public:
	void Update()override;
	void Draw(int modeldata)override;
private:
	float DegreeY;
	PlayerAction Current;
	PlayerAction Old;
	float AnimTotalTime,PlayTime;
	int AttachIndex;
};

#endif // !PLAYER_H

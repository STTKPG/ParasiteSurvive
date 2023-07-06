#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"
#include "ObjectManager.h"
#include "../Camera.h"

class Player : public ObjectBase
{
public:
	static Player* Instance()
	{
		static Player instance(ObjectType::Player,true,Vector(0,200,0));
		return &instance;
	}
	~Player(){}

public:
	Vector GetRotate()
	{
		return Rotate;
	}
	
public:
	void Update()override;

private:
	VECTOR TargetRotate;
	float DegreeY;
	float DegreeXZ;
	Camera camera;

private:
	Player(const Player& obj){}
	Player(ObjectType type, bool is_draw, Vector pos) : ObjectBase(type, is_draw, pos)
		, DegreeXZ(180)
		, DegreeY(180)
	{

	}
};

#endif // !PLAYER_H

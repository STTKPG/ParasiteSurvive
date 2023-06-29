#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectBase.h"
#include "ObjectManager.h"
#include "../Camera.h"

class Player : public ObjectBase
{
public:
	Player(ObjectType type,bool is_draw) : ObjectBase(type,is_draw)
	{

	}
	~Player(){}

public:
	Vector GetRotate()
	{
		return Rotate;
	}
protected:
	void Update()override;

private:
	VECTOR TargetRotate;
	float DegreeY;
	float DegreeXZ;
	Camera camera;
};

#endif // !PLAYER_H

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
	Player(ObjectType type,SceneBase::SceneKind scene, Vector pos,Vector rotate,Vector scale,Vector size = Vector(2,2,2)) : ObjectBase(type,scene, pos,rotate,scale,size)
		, DegreeY(180)
		, Current(Idle)
		,Old(Idle)
		,AnimTotalTime(0)
		,PlayTime(0)
		,AttachIndex(3)
		,Radius(10)
		,Is_Hit(false)
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
	void OnCollision(ObjectBase* Obj)
	{
		float ClampX;
		float ClampZ;
		float Direction;
		switch (Obj->Type)
		{
		case Wall:
			ClampX = clamp(Pos.Vec.x, Obj->Collider.MinX, Obj->Collider.MaxX);
			ClampZ = clamp(Pos.Vec.z, Obj->Collider.MinZ, Obj->Collider.MaxZ);
			Direction = (Pos.Vec.x - ClampX) * (Pos.Vec.x - ClampX) + (Pos.Vec.z - ClampZ) * (Pos.Vec.z - ClampZ);
			if (Direction <= Radius * Radius)
			{
				Is_Hit = true;
			}
		case WallDoor:
			ClampX = clamp(Pos.Vec.x, Obj->Collider.MinX, Obj->Collider.MaxX);
			ClampZ = clamp(Pos.Vec.z, Obj->Collider.MinZ, Obj->Collider.MaxZ);
			Direction = (Pos.Vec.x - ClampX) * (Pos.Vec.x - ClampX) + (Pos.Vec.z - ClampZ) * (Pos.Vec.z - ClampZ);
			if (Direction <= Radius * Radius)
			{
				Is_Hit = true;
			}
		case Door:
			ClampX = clamp(Pos.Vec.x, Obj->Collider.MinX, Obj->Collider.MaxX);
			ClampZ = clamp(Pos.Vec.z, Obj->Collider.MinZ, Obj->Collider.MaxZ);
			Direction = (Pos.Vec.x - ClampX) * (Pos.Vec.x - ClampX) + (Pos.Vec.z - ClampZ) * (Pos.Vec.z - ClampZ);
			if (Direction <= Radius * Radius)
			{
				if (CheckHitKey(KEY_INPUT_E))
				{
					CurrentScene = Obj->CurrentScene;
				}
				Is_Interact = true;
			}
			break;
		case BookCase:

			ClampX = clamp(Pos.Vec.x, Obj->Collider.MinX, Obj->Collider.MaxX);
			ClampZ = clamp(Pos.Vec.z, Obj->Collider.MinZ, Obj->Collider.MaxZ);
			Direction = (Pos.Vec.x - ClampX) * (Pos.Vec.x - ClampX) + (Pos.Vec.z - ClampZ) * (Pos.Vec.z - ClampZ);
			if (Direction <= Radius * Radius)
			{
				Message = Obj->Message;
			}
			break;
		default:
			break;
		}
	}

private:
	float clamp(float center,float min,float max)
	{
		if (center < min)
		{
			return min;
		}
		else if (center > max)
		{
			return max;
		}
		else
		{
			return center;
		}
	}
private:
	float DegreeY;
	PlayerAction Current;
	PlayerAction Old;
	float AnimTotalTime,PlayTime;
	int AttachIndex;
	bool Is_Hit;
	float Radius;
};

#endif // !PLAYER_H

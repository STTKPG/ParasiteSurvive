#ifndef OBJECTBASE_H
#define OBJECTBASE_H

#include "../Vector.h"
#include "../Matrix.h"
#include "../SceneFile/SceneBase.h"
#include <string>

class ObjectBase
{
public:
	enum ObjectType
	{
		Player,
		Enemy,
		Floor,
		Barrel,
		Target,
		Wall,
		WallDoor,
		Door,
		Arch,
		BookCase
	};
	struct HitBox
	{
		Vector Top1 = Vector(0, 0, 0);
		Vector Top2 = Vector(0, 0, 0);
		Vector Top3 = Vector(0, 0, 0);
		Vector Top4 = Vector(0, 0, 0);

		float MinX = 0;
		float MaxX = 0;
		float MinZ = 0;
		float MaxZ = 0;
	};
	
public:
	ObjectBase(ObjectType type,SceneBase::SceneKind scene,Vector pos = Vector(0,0,0), Vector rotate = Vector(0, 0, 0),Vector scale = Vector(1,1,1) ,Vector size = Vector(1,1,1),std::string message = "") :
	Pos(pos),
	Rotate(rotate),
	Scale(scale),
	Is_Alive(true),
	Type(type),
	CameraDirection(0),
	Size(size),
	Is_Interact(false),
		CurrentScene(scene),
		Hp(100),
		Message(message)
	{
		Matrix TM;
		TM.Translate(Pos.Vec);
		Matrix RM;
		RM.RotateY(Rotate.Vec.y);
		Matrix Mat = RM * TM;
		float X = Size.Vec.x / 2;
		float Z = Size.Vec.z / 2;
		Vector Top1(X, 0, Z), Top2(-X, 0, Z),
			   Top3(X, 0, -Z), Top4(-X, 0, -Z);

		Collider.Top1.Vec = VTransform(Top1.Vec, Mat.Mat);
		Collider.Top2.Vec = VTransform(Top2.Vec, Mat.Mat);
		Collider.Top3.Vec = VTransform(Top3.Vec, Mat.Mat);
		Collider.Top4.Vec = VTransform(Top4.Vec, Mat.Mat);

		if (Collider.Top1.Vec.x > Collider.Top4.Vec.x)
		{
			Collider.MinX = Collider.Top4.Vec.x;
			Collider.MaxX = Collider.Top1.Vec.x;
		}
		else
		{
			Collider.MinX = Collider.Top1.Vec.x;
			Collider.MaxX = Collider.Top4.Vec.x;
		}

		if (Collider.Top1.Vec.z > Collider.Top4.Vec.z)
		{
			Collider.MinZ = Collider.Top4.Vec.z;
			Collider.MaxZ = Collider.Top1.Vec.z;
		}
		else
		{
			Collider.MinZ = Collider.Top1.Vec.z;
			Collider.MaxZ = Collider.Top4.Vec.z;
		}
	}
	virtual ~ObjectBase() {}

public:
	virtual void Update() = 0;
	virtual void Draw(int modeldata)
	{
		MV1SetScale(modeldata,Scale.Vec);
		MV1SetRotationXYZ(modeldata, Rotate.Vec);
		MV1SetPosition(modeldata, Pos.Vec);
		MV1DrawModel(modeldata);
		
		int Green = GetColor(0, 255, 0);
		DrawLine3D(Collider.Top1.Vec, Collider.Top2.Vec, Green);
		DrawLine3D(Collider.Top2.Vec, Collider.Top3.Vec, Green);
		DrawLine3D(Collider.Top3.Vec, Collider.Top4.Vec, Green);
		DrawLine3D(Collider.Top4.Vec, Collider.Top1.Vec, Green);
	
	}
	virtual void OnCollision(ObjectBase* Obj){}

public:
	Vector Pos;
	Vector Rotate;
	Vector Scale;
	ObjectType Type;
	float CameraDirection;
	bool Is_Alive;
	int Hp;
	Vector Size;
	HitBox Collider;
	bool Is_Interact;
	SceneBase::SceneKind CurrentScene;
	std::string Message;
};

#endif
//
//Vector Top1(Pos.Vec.x + X, 0, Pos.Vec.z + Z), Top2(Pos.Vec.x - X, 0, Pos.Vec.z + Z),
//Top3(Pos.Vec.x + X, 0, Pos.Vec.z - Z), Top4(Pos.Vec.x - X, 0, Pos.Vec.z - Z),
//Prop1(Pos.Vec.x + X, 100, Pos.Vec.z + Z), Prop2(Pos.Vec.x - X, 100, Pos.Vec.z + Z),
//Prop3(Pos.Vec.x + X, 100, Pos.Vec.z - Z), Prop4(Pos.Vec.x - X, 100, Pos.Vec.z - Z);
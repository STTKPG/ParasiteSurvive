#ifndef CAMERA_H
#define CAMERA_H

#include "DxLib.h"
#include "Vector.h"

class Camera
{
public:
	Camera(Vector pos, Vector target,int cnear = 0, int cfar = 1000) :
		Near(cnear),Far(cfar),Pos(pos),Target(target)
	{
		SetCameraNearFar(Near, Far);
		SetCameraPositionAndTargetAndUpVec(Pos.Vec, Target.Vec, Vector(0,1,0).Vec);
	}
	~Camera() {}

public:
	void SetTarget(VECTOR target);
	void SetPositionAndTargetAndUpVec(Vector pos, Vector target, Vector upvec);
	void SetPositionAndTarget(Vector pos, Vector target);
	void SetCameraPositionAndRotate(VECTOR pos, float vrota,float hrota);
	Vector GetPos()
	{
		return Pos;	
	}

private:
	int Near;
	int Far;
	Vector Pos;
	Vector Target;

};

#endif // !CAMERA_H
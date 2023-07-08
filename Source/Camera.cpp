#include "Camera.h"
#include "Matrix.h"
#include "Vector.h"
#include "Quaternion.h" 
#include <iostream>
#include <algorithm>

using namespace std;

void Camera::SetTarget(VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(Pos.Vec, target, VGet(0, 1, 0));
}

void Camera::SetPositionAndTargetAndUpVec(Vector pos, Vector target, Vector upvec)
{
	SetCameraPositionAndTargetAndUpVec(pos.Vec, target.Vec, upvec.Vec);
}

void Camera::SetPositionAndTarget(Vector pos, Vector target)
{
	float Rad = pos.Vec.y;
	Vector OPos(0, 0, 0);
	OPos += target;
	Vector Rotate(sinf(Rad), 0, cosf(Rad));

	OPos += Rotate * Vector(300,0,300);
	OPos += Vector(0, 300, 0);

	Pos = OPos;
	Vector Target(target);
	Target += Vector(0, 100, 0);
	SetCameraPositionAndTargetAndUpVec(Pos.Vec, Target.Vec, VGet(0, 1, 0));
}

void Camera::SetCameraPositionAndRotate(VECTOR pos, float vrota, float hrota)
{

	SetCameraPositionAndAngle(pos, vrota, hrota, 0);
}
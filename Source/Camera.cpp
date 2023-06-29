#include "Camera.h"
#include "Matrix.h"
#include "Vector.h"
#include "Quaternion.h" 

void Camera::SetTarget(VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(Pos, target, VGet(0, 1, 0));
}

void Camera::SetPositionAndTargetAndUpVec(VECTOR pos, VECTOR target,VECTOR upvec)
{
	SetCameraPositionAndTargetAndUpVec(pos, target, upvec);
}

void Camera::SetPositionAndTarget(VECTOR pos, VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(pos, target, VGet(0, 1, 1000));
}

void Camera::SetCameraPositionAndRotate(VECTOR pos, float vrota, float hrota)
{
	SetCameraPositionAndAngle(pos, vrota, hrota, 0);
}
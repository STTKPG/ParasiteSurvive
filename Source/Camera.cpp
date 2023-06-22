#include "Camera.h"

void Camera::SetTarget(VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(Pos, target, VGet(0, 1, 0));
}

void Camera::SetPositionAndTarget(VECTOR pos, VECTOR target)
{
	Pos = pos;
	Target = target;
	SetCameraPositionAndTargetAndUpVec(Pos, Target, VGet(0, 1, 0));
}
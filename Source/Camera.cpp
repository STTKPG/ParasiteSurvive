#include "Camera.h"

void Camera::SetTarget(VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(Pos, target, VGet(0, 1, 0));
}

void Camera::SetPositionAndTarget(VECTOR pos, VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(pos, target, VGet(0, 1, 0));
}
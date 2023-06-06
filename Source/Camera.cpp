#include "Camera.h"

void Camera::SetTarget(VECTOR target)
{
	SetCameraPositionAndTargetAndUpVec(Pos, target, VGet(0, 1, 0));
}

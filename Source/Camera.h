#ifndef CAMERA_H
#define CAMERA_H

#include "DxLib.h"

class Camera
{
public:
	Camera()
	{
		SetCameraNearFar(Near, Far);
		SetCameraPositionAndTargetAndUpVec(Pos, Target, VGet(0, 1, 0));
	}
	~Camera(){}

public:
	void SetTarget(VECTOR target);

private:
	int Near;
	int Far;
	VECTOR Pos;
	VECTOR Target;

};

#endif // !CAMERA_H

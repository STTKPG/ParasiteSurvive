#ifndef CAMERA_H
#define CAMERA_H

#include "DxLib.h"

class Camera
{
public:
	Camera(int cnear = 0, int cfar = 1000,VECTOR pos = VGet(0,0,0), VECTOR target = VGet(0, 0, 1)) :
		Near(cnear),Far(cfar),Pos(pos),Target(target)
	{
		SetCameraNearFar(Near, Far);
		SetCameraPositionAndTargetAndUpVec(Pos, Target, VGet(0, 1, 0));
	}
	~Camera() {}

public:
	void SetTarget(VECTOR target);
	void SetPositionAndTarget(VECTOR pos, VECTOR target);
	void Update();

private:
	int Near;
	int Far;
	VECTOR Pos;
	VECTOR Target;

};

#endif // !CAMERA_H
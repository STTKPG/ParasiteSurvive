#ifndef HITBOX_H
#define HITBOX_H

#include "Vector.h"

class HitBox
{
	struct Circle
	{
		Vector Op;
		float Half;
	};

	struct Rect
	{
		Vector Op;
		Vector Size;
	};
public:
	HitBox(Vector size,Vector orizin){}
	~HitBox(){}

public:
	bool CircleAndMRect(Circle circle,Rect mrect)
	{
		float LengthX = (mrect.Size.Vec.x / 2) + circle.Half;
		float LengthZ = (mrect.Size.Vec.z / 2) + circle.Half;
		float DirectionX = sqrtf((circle.Op.Vec.x - mrect.Op.Vec.x) * (circle.Op.Vec.x - mrect.Op.Vec.x));
		float DirectionZ = sqrtf((circle.Op.Vec.z - mrect.Op.Vec.z) * (circle.Op.Vec.z - mrect.Op.Vec.z));

		if (DirectionX < LengthX||DirectionZ < LengthZ)
		{
			return true;
		}
		return false;
	}

private:


};

#endif // !HITBOX_H

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include "DxLib.h"

class Vector
{
public:
	VECTOR Vec;

public:
	Vector(float x,float y,float z) : Vec(VGet(x,y,z)){}
	~Vector(){}

public:
	Vector operator + (Vector r)
	{
		return Vector(this->Vec.x + r.Vec.x,
			          this->Vec.y + r.Vec.y,
			          this->Vec.z + r.Vec.z);
	}

	Vector operator - (Vector r)
	{
		return Vector(this->Vec.x - r.Vec.x,
			          this->Vec.y - r.Vec.y,
			          this->Vec.z - r.Vec.z);
	}

	Vector operator * (Vector r)
	{
		return Vector(this->Vec.x * r.Vec.x,
			          this->Vec.y * r.Vec.y,
			          this->Vec.z * r.Vec.z);
	}

	Vector operator / (Vector r)
	{
		return Vector(this->Vec.x / r.Vec.x,
			          this->Vec.y / r.Vec.y,
			          this->Vec.z / r.Vec.z);
	}

	Vector Normal()
	{
		float Direction = sqrtf(this->Vec.x * this->Vec.x + this->Vec.y * this->Vec.y + this->Vec.z * this->Vec.z);
		return Vector(this->Vec.x / Direction,
			          this->Vec.y / Direction,
			          this->Vec.z / Direction);
	}
};

#endif // !VECTOR_H

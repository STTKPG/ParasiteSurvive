#ifndef VECTOR_H
#define VECTOR_H

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
};

#endif // !VECTOR_H

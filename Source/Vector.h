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
	Vector(const Vector& c)
	{
		this->Vec.x = c.Vec.x;
		this->Vec.y = c.Vec.y;
		this->Vec.z = c.Vec.z;
	}
public:
	Vector operator + (const Vector &r) const
	{
		return Vector(this->Vec.x + r.Vec.x,
			          this->Vec.y + r.Vec.y,
			          this->Vec.z + r.Vec.z);
	}

	Vector operator - (const Vector &r) const
	{
		return Vector(this->Vec.x - r.Vec.x,
			          this->Vec.y - r.Vec.y,
			          this->Vec.z - r.Vec.z);
	}

	Vector operator * (const Vector &r) const
	{
		return Vector(this->Vec.x * r.Vec.x,
			          this->Vec.y * r.Vec.y,
			          this->Vec.z * r.Vec.z);
	}

	Vector operator / (const Vector &r) const
	{
		return Vector(this->Vec.x / r.Vec.x,
			          this->Vec.y / r.Vec.y,
			          this->Vec.z / r.Vec.z);
	}

	Vector& operator = (const Vector& r)
	{
		this->Vec.x = r.Vec.x;
		this->Vec.y = r.Vec.y;
		this->Vec.z = r.Vec.z;

		return *this;
	}

	Vector& operator += (Vector r)
	{
		this->Vec.x += r.Vec.x;
		this->Vec.y += r.Vec.y;
		this->Vec.z += r.Vec.z;

		return *this;
	}

	Vector& operator -= (Vector r)
	{
		this->Vec.x -= r.Vec.x;
		this->Vec.y -= r.Vec.y;
		this->Vec.z -= r.Vec.z;

		return *this;
	}

	Vector Xvec()
	{
		return Vector(this->Vec.x * 1, 0, 0);
	}

	Vector XZVec()
	{
		return Vector(this->Vec.x, 0, this->Vec.z);
	}

	Vector Normal()
	{
		float Direction = this->Length();
		return Vector(this->Vec.x / Direction,
			          this->Vec.y / Direction,
			          this->Vec.z / Direction);
	}

	float Length()
	{
		float Direction = sqrtf(this->Vec.x * this->Vec.x + this->Vec.y * this->Vec.y + this->Vec.z * this->Vec.z);
		return Direction;
	}
};

#endif // !VECTOR_H

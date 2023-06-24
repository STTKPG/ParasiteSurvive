#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>

class Quaternion
{
public:
	Quaternion(float w,float x,float y,float z):
	W(w),X(x),
	Y(y),Z(z){}
	~Quaternion(){}

	Quaternion Conplex(Quaternion q)
	{
		return Quaternion(q.W, -q.X, -q.Y, -q.Z);
	}

	Quaternion operator *(Quaternion q)
	{
		return Quaternion(this->W * q.W - this->X * q.X - this->Y * q.Y - this->Z * q.Z,
			              this->W * q.X + this->X * q.W + this->Y * q.Z - this->Z * q.Y,
			              this->W * q.Y - this->X * q.Z + this->Y * q.W + this->Z * q.X,
			              this->W * q.Z + this->X * q.Y - this->Y * q.X + this->Z * q.W);

	}


public:
	float W;
	float X;
	float Y;
	float Z;
	
};
#endif // !QUATERNION_H

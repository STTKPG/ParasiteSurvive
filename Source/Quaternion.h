#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>
#include "Vector.h"
class Quaternion
{
public:
	Quaternion(float w, float x, float y, float z) :
	W(w),X(x),
	Y(y),Z(z){}
	/*Quaternion(Vector axis, float rad)
	{
		float HalfSin = sin(rad * 0.5f);
		float HalfCos = cos(rad * 0.5f);

		W = HalfCos;
		X = axis.Normal().Vec.x * HalfSin;
		Y = axis.Normal().Vec.y * HalfSin;
		Z = axis.Normal().Vec.z * HalfSin;
	}*/
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

	Quaternion MakeCameraQuaX(Vector axis, float rad)
	{

		float HalfSin = sin(rad * 0.5f);
		float HalfCos = cos(rad * 0.5f);

		return Quaternion(HalfCos,
			              axis.Normal().Vec.x * HalfSin,
			              axis.Normal().Vec.y * HalfSin,
			              axis.Normal().Vec.z * HalfSin);
	}

	Vector RotateQuaternionPosition(Vector axis,float rad)
	{
		Quaternion quaternion = MakeCameraQuaX(axis, rad);
		Quaternion conplexquaternion = 
	}

public:
	float W;
	float X;
	float Y;
	float Z;
	
};
#endif // !QUATERNION_H

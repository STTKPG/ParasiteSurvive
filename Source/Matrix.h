#ifndef MATRIX_H
#define MATRIX_H

#include "DxLib.h"

class Matrix
{
public:
	Matrix(MATRIX mat = MGetIdent()) : 
	Mat(mat){}
	~Matrix(){}

public:
	Matrix operator * (Matrix mat)
	{
		Matrix Mat;
		Mat.Mat.m[0][0] = this->Mat.m[0][0] * mat.Mat.m[0][0] + this->Mat.m[0][1] * mat.Mat.m[1][0] + this->Mat.m[0][2] * mat.Mat.m[2][0] + this->Mat.m[0][3] * mat.Mat.m[3][0];
		Mat.Mat.m[0][1] = this->Mat.m[0][0] * mat.Mat.m[0][1] + this->Mat.m[0][1] * mat.Mat.m[1][1] + this->Mat.m[0][2] * mat.Mat.m[2][1] + this->Mat.m[0][3] * mat.Mat.m[3][1];
		Mat.Mat.m[0][2] = this->Mat.m[0][0] * mat.Mat.m[0][2] + this->Mat.m[0][1] * mat.Mat.m[1][2] + this->Mat.m[0][2] * mat.Mat.m[2][2] + this->Mat.m[0][3] * mat.Mat.m[3][2];
		Mat.Mat.m[0][3] = this->Mat.m[0][0] * mat.Mat.m[0][3] + this->Mat.m[0][1] * mat.Mat.m[1][3] + this->Mat.m[0][2] * mat.Mat.m[2][3] + this->Mat.m[0][3] * mat.Mat.m[3][3];
		   
		Mat.Mat.m[1][0] = this->Mat.m[1][0] * mat.Mat.m[0][0] + this->Mat.m[1][1] * mat.Mat.m[1][0] + this->Mat.m[1][2] * mat.Mat.m[2][0] + this->Mat.m[1][3] * mat.Mat.m[3][0];
		Mat.Mat.m[1][1] = this->Mat.m[1][0] * mat.Mat.m[0][1] + this->Mat.m[1][1] * mat.Mat.m[1][1] + this->Mat.m[1][2] * mat.Mat.m[2][1] + this->Mat.m[1][3] * mat.Mat.m[3][1];
		Mat.Mat.m[1][2] = this->Mat.m[1][0] * mat.Mat.m[0][2] + this->Mat.m[1][1] * mat.Mat.m[1][2] + this->Mat.m[1][2] * mat.Mat.m[2][2] + this->Mat.m[1][3] * mat.Mat.m[3][2];
		Mat.Mat.m[1][3] = this->Mat.m[1][0] * mat.Mat.m[0][3] + this->Mat.m[1][1] * mat.Mat.m[1][3] + this->Mat.m[1][2] * mat.Mat.m[2][3] + this->Mat.m[1][3] * mat.Mat.m[3][3];
		   
		Mat.Mat.m[2][0] = this->Mat.m[2][0] * mat.Mat.m[0][0] + this->Mat.m[2][1] * mat.Mat.m[1][0] + this->Mat.m[2][2] * mat.Mat.m[2][0] + this->Mat.m[2][3] * mat.Mat.m[3][0];
		Mat.Mat.m[2][1] = this->Mat.m[2][0] * mat.Mat.m[0][1] + this->Mat.m[2][1] * mat.Mat.m[1][1] + this->Mat.m[2][2] * mat.Mat.m[2][1] + this->Mat.m[2][3] * mat.Mat.m[3][1];
		Mat.Mat.m[2][2] = this->Mat.m[2][0] * mat.Mat.m[0][2] + this->Mat.m[2][1] * mat.Mat.m[1][2] + this->Mat.m[2][2] * mat.Mat.m[2][2] + this->Mat.m[2][3] * mat.Mat.m[3][2];
		Mat.Mat.m[2][3] = this->Mat.m[2][0] * mat.Mat.m[0][3] + this->Mat.m[2][1] * mat.Mat.m[1][3] + this->Mat.m[2][2] * mat.Mat.m[2][3] + this->Mat.m[2][3] * mat.Mat.m[3][3];
		   
		Mat.Mat.m[3][0] = this->Mat.m[3][0] * mat.Mat.m[0][0] + this->Mat.m[3][1] * mat.Mat.m[1][0] + this->Mat.m[3][2] * mat.Mat.m[2][0] + this->Mat.m[3][3] * mat.Mat.m[3][0];
		Mat.Mat.m[3][1] = this->Mat.m[3][0] * mat.Mat.m[0][1] + this->Mat.m[3][1] * mat.Mat.m[1][1] + this->Mat.m[3][2] * mat.Mat.m[2][1] + this->Mat.m[3][3] * mat.Mat.m[3][1];
		Mat.Mat.m[3][2] = this->Mat.m[3][0] * mat.Mat.m[0][2] + this->Mat.m[3][1] * mat.Mat.m[1][2] + this->Mat.m[3][2] * mat.Mat.m[2][2] + this->Mat.m[3][3] * mat.Mat.m[3][2];
		Mat.Mat.m[3][3] = this->Mat.m[3][0] * mat.Mat.m[0][3] + this->Mat.m[3][1] * mat.Mat.m[1][3] + this->Mat.m[3][2] * mat.Mat.m[2][3] + this->Mat.m[3][3] * mat.Mat.m[3][3];

		return Mat;
	}

	void Identity()
	{
		this->Mat = MGetIdent();
	}
	void RotateX(float xaxis)
	{
		this->Mat = MGetRotX(xaxis);
	}
	void RotateY(float yaxis)
	{
		this->Mat = MGetRotY(yaxis);
	}
	void RotateZ(float zaxis)
	{
		this->Mat = MGetRotZ(zaxis);
	}
	void Translate(VECTOR trans)
	{
		this->Mat = MGetTranslate(trans);
	}
	void Scale(VECTOR scale)
	{
		this->Mat = MGetScale(scale);
	}
	void Inverse()
	{
		this->Mat = MInverse(this->Mat);
	}
	VECTOR Zvec()
	{
		return VTransform(VGet(0, 0, 1),MMult(this->Mat,MGetTranslate(VTransform(VGet(0, 0, 0), this->Mat))));
	}

public:
	MATRIX Mat;

};









#endif // !MATRIX

//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Gam 475
//----------------------------------------------------------------------------- 

#include "wfpch.h"

#include <math.h>
#include "Maths/include/MathEngine.h"

// ---  End of File ---------------

Matrix::Matrix()
{
	this->_v0 = Vect(0, 0, 0, 0);
	this->_v1 = Vect(0, 0, 0, 0);
	this->_v2 = Vect(0, 0, 0, 0);
	this->_v3 = Vect(0, 0, 0, 0);
}

Matrix::Matrix(Vect v0, Vect v1, Vect v2, Vect v3)
{
	this->_v0 = v0;
	this->_v1 = v1;
	this->_v2 = v2;
	this->_v3 = v3;
}

Matrix::Matrix(Quat q)
{
	float qx = q[x];
	float qy = q[y];
	float qz = q[z];
	float qw = q[w];

	this->_m0 = 1 - (2 * (qy * qy + qz * qz));
	this->_m1 = 2 * (qx * qy + qw * qz);
	this->_m2 = 2 * (qx * qz - qw * qy);
	this->_m3 = 0;

	this->_m4 = 2 * (qx * qy - qw * qz);
	this->_m5 = 1 - (2 * (qx * qx + qz * qz));
	this->_m6 = 2 * (qy * qz + qw * qx);
	this->_m7 = 0;

	this->_m8 = 2 * (qx * qz + qw * qy);
	this->_m9 = 2 * (qy * qz - qw * qx);
	this->_m10 = 1 - (2 * (qx * qx + qy * qy));
	this->_m11 = 0;

	this->_m12 = 0;
	this->_m13 = 0;
	this->_m14 = 0;
	this->_m15 = 1;
}

void Matrix::set(Matrix::RowType row, Vect v)
{
	if (row == Matrix::RowType::Row_0) {
		this->_v0 = v;
	}
	else if (row == Matrix::RowType::Row_1) {
		this->_v1 = v;
	}
	else if (row == Matrix::RowType::Row_2) {
		this->_v2 = v;
	}
	else if (row == Matrix::RowType::Row_3) {
		this->_v3 = v;
	}

}

void Matrix::set(Vect v0, Vect v1, Vect v2, Vect v3)
{
	this->_v0 = v0;
	this->_v1 = v1;
	this->_v2 = v2;
	this->_v3 = v3;
}

void Matrix::set(Quat q)
{
	float qx = q[x];
	float qy = q[y];
	float qz = q[z];
	float qw = q[w];

	this->_m0 = 1 - (2 * (qy * qy + qz * qz));
	this->_m1 = 2 * (qx * qy + qw * qz);
	this->_m2 = 2 * (qx * qz - qw * qy);
	this->_m3 = 0; 

	this->_m4 = 2 * (qx * qy - qw * qz);
	this->_m5 = 1 - (2 * (qx * qx + qz * qz));
	this->_m6 = 2 * (qy * qz + qw * qx);
	this->_m7 = 0;

	this->_m8 = 2 * (qx * qz + qw * qy);
	this->_m9 = 2 * (qy * qz - qw * qx);
	this->_m10 = 1 - (2 * (qx * qx + qy * qy));
	this->_m11 = 0;

	this->_m12 = 0;
	this->_m13 = 0;
	this->_m14 = 0;
	this->_m15 = 1;

}

Vect Matrix::get(Matrix::RowType row)
{
	Vect v;
	if (row == Matrix::RowType::Row_0) {
		v = this->_v0;
	}
	else if (row == Matrix::RowType::Row_1) {
		v = this->_v1;
	}
	else if (row == Matrix::RowType::Row_2) {
		v = this->_v2;
	}
	else if (row == Matrix::RowType::Row_3) {
		v = this->_v3;
	}
	return v;
}

Matrix::Matrix(Matrix::SpecialType type)
{
	if (type == Matrix::SpecialType::Identity) {
		this->_v0 = Vect(1, 0, 0, 0);
		this->_v1 = Vect(0, 1, 0, 0);
		this->_v2 = Vect(0, 0, 1, 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (type == Matrix::SpecialType::Zero) {
		*this = Matrix();
	}
}

void Matrix::set(Matrix::SpecialType type)
{
	if (type == Matrix::SpecialType::Identity) {
		this->_v0 = Vect(1, 0, 0, 0);
		this->_v1 = Vect(0, 1, 0, 0);
		this->_v2 = Vect(0, 0, 1, 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (type == Matrix::SpecialType::Zero) {
		*this = Matrix();
	}
}

Matrix::Matrix(Matrix::TransType, float x, float y, float z)
{
	this->_v0 = Vect(1, 0, 0, 0);
	this->_v1 = Vect(0, 1, 0, 0);
	this->_v2 = Vect(0, 0, 1, 0);
	this->_v3 = Vect(x, y, z, 1);
}

Matrix::Matrix(Matrix::TransType, Vect v)
{
	this->_v0 = Vect(1, 0, 0, 0);
	this->_v1 = Vect(0, 1, 0, 0);
	this->_v2 = Vect(0, 0, 1, 0);
	this->_v3 = v;
}

void Matrix::set(Matrix::TransType, float x, float y, float z)
{
	this->_v0 = Vect(1, 0, 0, 0);
	this->_v1 = Vect(0, 1, 0, 0);
	this->_v2 = Vect(0, 0, 1, 0);
	this->_v3 = Vect(x, y, z, 1);
}

void Matrix::set(Matrix::TransType, Vect v)
{
	this->_v0 = Vect(1, 0, 0, 0);
	this->_v1 = Vect(0, 1, 0, 0);
	this->_v2 = Vect(0, 0, 1, 0);
	this->_v3 = v;
}

Matrix::Matrix(Matrix::ScaleType, float x, float y, float z)
{
	this->_v0 = Vect(x, 0, 0, 0);
	this->_v1 = Vect(0, y, 0, 0);
	this->_v2 = Vect(0, 0, z, 0);
	this->_v3 = Vect(0, 0, 0, 1);
}

Matrix::Matrix(Matrix::ScaleType, Vect v)
{
	this->_v0 = Vect(v[x], 0, 0, 0);
	this->_v1 = Vect(0, v[y], 0, 0);
	this->_v2 = Vect(0, 0, v[z], 0);
	this->_v3 = Vect(0, 0, 0, 1);
}

void Matrix::set(Matrix::ScaleType, float x, float y, float z)
{
	this->_v0 = Vect(x, 0, 0, 0);
	this->_v1 = Vect(0, y, 0, 0);
	this->_v2 = Vect(0, 0, z, 0);
	this->_v3 = Vect(0, 0, 0, 1);
}

void Matrix::set(Matrix::ScaleType, Vect v)
{
	this->_v0 = Vect(v[x], 0, 0, 0);
	this->_v1 = Vect(0, v[y], 0, 0);
	this->_v2 = Vect(0, 0, v[z], 0);
	this->_v3 = Vect(0, 0, 0, 1);
}

Matrix::Matrix(Matrix::RotType axis, float theta)
{
	if (axis == Matrix::RotType::Rot_X) {
		this->_v0 = Vect(1, 0, 0, 0);
		this->_v1 = Vect(0, cosf(theta), sinf(theta), 0);
		this->_v2 = Vect(0, -sinf(theta), cosf(theta), 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (axis == Matrix::RotType::Rot_Y) {
		this->_v0 = Vect(cosf(theta), 0, -sinf(theta), 0);
		this->_v1 = Vect(0, 1, 0, 0);
		this->_v2 = Vect(sinf(theta), 0, cosf(theta), 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (axis == Matrix::RotType::Rot_Z) {
		this->_v0 = Vect(cosf(theta), sinf(theta), 0, 0);
		this->_v1 = Vect(-sinf(theta), cosf(theta), 0, 0);
		this->_v2 = Vect(0, 0, 1, 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}
}

void Matrix::set(Matrix::RotType axis, float theta)
{
	if (axis == Matrix::RotType::Rot_X) {
		this->_v0 = Vect(1, 0, 0, 0);
		this->_v1 = Vect(0, cosf(theta), sinf(theta), 0);
		this->_v2 = Vect(0, -sinf(theta), cosf(theta), 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (axis == Matrix::RotType::Rot_Y) {
		this->_v0 = Vect(cosf(theta), 0, -sinf(theta), 0);
		this->_v1 = Vect(0, 1, 0, 0);
		this->_v2 = Vect(sinf(theta), 0, cosf(theta), 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}

	else if (axis == Matrix::RotType::Rot_Z) {
		this->_v0 = Vect(cosf(theta), sinf(theta), 0, 0);
		this->_v1 = Vect(-sinf(theta), cosf(theta), 0, 0);
		this->_v2 = Vect(0, 0, 1, 0);
		this->_v3 = Vect(0, 0, 0, 1);
	}
}

Matrix::Matrix(Matrix::Rot3AngleType, float x, float y, float z)
{
	*this = Quat(Quat::RotType::Rot_X,x) * Quat(Quat::RotType::Rot_Y,y) * Quat(Quat::RotType::Rot_Z,z);
}

void Matrix::set(Matrix::Rot3AngleType, float x, float y, float z)
{
	*this = Quat(Quat::RotType::Rot_X, x) * Quat(Quat::RotType::Rot_Y, y) * Quat(Quat::RotType::Rot_Z, z);
}

Matrix::Matrix(Matrix::RotAxisAngleType,  Vect v, float theta)
{
	Vect n = v.getNorm();

	float angle = sinf(theta / 2.0f);

	Quat q(n[x] * angle, n[y] * angle, n[z] * angle, cosf(theta / 2.0f));
	//q = q* 0.5f;
	//float angle = 2.0f * acosf(theta);

	*this = q;
}

void Matrix::set(Matrix::RotAxisAngleType, Vect v, float theta)
{
	Vect n = v.getNorm();

	float angle = sinf(theta / 2.0f);

	Quat q(n[x] * angle, n[y] * angle, n[z] * angle, cosf(theta / 2.0f));
	//q = q* 0.5f;
	//float angle = 2.0f * acosf(theta);

	*this = q;
}

Matrix::Matrix(Matrix::RotOrientType type, Vect vUp, Vect vDir)
{
	// normalize the vectors

	vDir.norm();
	vUp.norm();

	// create y x DOF 

	Vect vRight = (vUp.cross(vDir));

	// set matrix

	if (type == RotOrientType::RotOrient)
	{
		this->_m0 = vRight[x];
		this->_m1 = vRight[y];
		this->_m2 = vRight[z];
		this->_m3 = 0.0f;

		this->_m4 = vUp[x];
		this->_m5 = vUp[y];
		this->_m6 = vUp[z];
		this->_m7 = 0.0f;

		this->_m8 = vDir[x];
		this->_m9 = vDir[y];
		this->_m10 = vDir[z];
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}
	else if (type == RotOrientType::RotInverseOrient)
	{
		this->_m0 = vRight[x];
		this->_m1 = vUp[x];
		this->_m2 = vDir[x];
		this->_m3 = 0.0f;

		this->_m4 = vRight[y];
		this->_m5 = vUp[y];
		this->_m6 = vDir[y];
		this->_m7 = 0.0f;

		this->_m8 = vRight[z];
		this->_m9 = vUp[z];
		this->_m10 = vDir[z];
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}
}
void Matrix::set(Matrix::RotOrientType type, Vect vUp, Vect vDir)
{
	// normalize the vectors

	vDir.norm();
	vUp.norm();

	// create y x DOF 

	Vect vRight = (vUp.cross(vDir));

	// set matrix

	if (type == RotOrientType::RotOrient)
	{
		this->_m0 = vRight[x];
		this->_m1 = vRight[y];
		this->_m2 = vRight[z];
		this->_m3 = 0.0f;

		this->_m4 = vUp[x];
		this->_m5 = vUp[y];
		this->_m6 = vUp[z];
		this->_m7 = 0.0f;

		this->_m8 = vDir[x];
		this->_m9 = vDir[y];
		this->_m10 = vDir[z];
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}
	else if (type == RotOrientType::RotInverseOrient)
	{
		this->_m0 = vRight[x];
		this->_m1 = vUp[x];
		this->_m2 = vDir[x];
		this->_m3 = 0.0f;

		this->_m4 = vRight[y];
		this->_m5 = vUp[y];
		this->_m6 = vDir[y];
		this->_m7 = 0.0f;

		this->_m8 = vRight[z];
		this->_m9 = vUp[z];
		this->_m10 = vDir[z];
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}
}

bool Matrix::isEqual(Matrix m, float theta)
{

	bool b0 = this->_v0.isEqual(m._v0, theta);
	bool b1 = this->_v1.isEqual(m._v1, theta);
	bool b2 = this->_v2.isEqual(m._v2, theta);
	bool b3 = this->_v3.isEqual(m._v3, theta);

	return b0 && b1 && b2 && b3;
}

bool Matrix::isIdentity(float theta)
{
	return this->isEqual(Matrix::Identity, theta);
}

Matrix Matrix::operator+()
{
	return *this;
}

Matrix Matrix::operator+(Matrix m)
{
	return Matrix(Vect(this->_v0[x] + m._v0[x], this->_v0[y] + m._v0[y], this->_v0[z] + m._v0[z], this->_v0[w] + m._v0[w]),
		Vect(this->_v1[x] + m._v1[x], this->_v1[y] + m._v1[y], this->_v1[z] + m._v1[z], this->_v1[w] + m._v1[w]),
		Vect(this->_v2[x] + m._v2[x], this->_v2[y] + m._v2[y], this->_v2[z] + m._v2[z], this->_v2[w] + m._v2[w]),
		Vect(this->_v3[x] + m._v3[x], this->_v3[y] + m._v3[y], this->_v3[z] + m._v3[z], this->_v3[w] + m._v3[w]));
}

void Matrix::operator+=(Matrix m)
{
	this->_v0.MatrixAdd(m._v0);
	this->_v1.MatrixAdd(m._v1);
	this->_v2.MatrixAdd(m._v2);
	this->_v3.MatrixAdd(m._v3);
}

Matrix Matrix::operator-()
{
	return Matrix(Vect(-this->_v0[x], -this->_v0[y], -this->_v0[z], -this->_v0[w]),
		Vect(-this->_v1[x], -this->_v1[y], -this->_v1[z], -this->_v1[w]),
		Vect(-this->_v2[x], -this->_v2[y], -this->_v2[z], -this->_v2[w]),
		Vect(-this->_v3[x], -this->_v3[y], -this->_v3[z], -this->_v3[w]));
}

Matrix Matrix::operator-(Matrix m)
{
	return Matrix(Vect(this->_v0[x] - m._v0[x], this->_v0[y] - m._v0[y], this->_v0[z] - m._v0[z], this->_v0[w] - m._v0[w]),
		Vect(this->_v1[x] - m._v1[x], this->_v1[y] - m._v1[y], this->_v1[z] - m._v1[z], this->_v1[w] - m._v1[w]),
		Vect(this->_v2[x] - m._v2[x], this->_v2[y] - m._v2[y], this->_v2[z] - m._v2[z], this->_v2[w] - m._v2[w]),
		Vect(this->_v3[x] - m._v3[x], this->_v3[y] - m._v3[y], this->_v3[z] - m._v3[z], this->_v3[w] - m._v3[w]));
}

void Matrix::operator-=(Matrix m)
{
	this->_v0.MatrixSub(m._v0);
	this->_v1.MatrixSub(m._v1);
	this->_v2.MatrixSub(m._v2);
	this->_v3.MatrixSub(m._v3);
}

Matrix Matrix::operator*(const float s)
{
	return Matrix(Vect(this->_v0[x] * s, this->_v0[y] * s, this->_v0[z] * s, this->_v0[w] * s),
		Vect(this->_v1[x] * s, this->_v1[y] * s, this->_v1[z] * s, this->_v1[w] * s),
		Vect(this->_v2[x] * s, this->_v2[y] * s, this->_v2[z] * s, this->_v2[w] * s),
		Vect(this->_v3[x] * s, this->_v3[y] * s, this->_v3[z] * s, this->_v3[w] * s));
}

void Matrix::operator*=(const float s)
{
	this->_v0.MatrixScale(s);
	this->_v1.MatrixScale(s);
	this->_v2.MatrixScale(s);
	this->_v3.MatrixScale(s);
}


Matrix & Matrix::operator=(const Matrix & m)
{
	this->_v0 = m._v0;
	this->_v1 = m._v1;
	this->_v2 = m._v2;
	this->_v3 = m._v3;

	return *this;
}


Matrix operator*(float s, const Matrix & v)
{
	return Matrix(Vect(v._v0[x] * s, v._v0[y] * s, v._v0[z] * s, v._v0[w] * s),
		Vect(v._v1[x] * s, v._v1[y] * s, v._v1[z] * s, v._v1[w] * s),
		Vect(v._v2[x] * s, v._v2[y] * s, v._v2[z] * s, v._v2[w] * s),
		Vect(v._v3[x] * s, v._v3[y] * s, v._v3[z] * s, v._v3[w] * s));
}


Matrix Matrix::operator*(Matrix m)
{
	float m0 = this->_m0*m._m0 + this->_m1 * m._m4 + this->_m2*m._m8 + this->_m3 * m._m12;
	float m1 = this->_m0*m._m1 + this->_m1 * m._m5 + this->_m2*m._m9 + this->_m3 * m._m13;
	float m2 = this->_m0*m._m2 + this->_m1 * m._m6 + this->_m2*m._m10 + this->_m3 * m._m14;
	float m3 = this->_m0*m._m3 + this->_m1 * m._m7 + this->_m2*m._m11 + this->_m3 * m._m15;

	float m4 = this->_m4*m._m0 + this->_m5 * m._m4 + this->_m6*m._m8 + this->_m7 * m._m12;
	float m5 = this->_m4*m._m1 + this->_m5 * m._m5 + this->_m6*m._m9 + this->_m7 * m._m13;
	float m6 = this->_m4*m._m2 + this->_m5 * m._m6 + this->_m6*m._m10 + this->_m7 * m._m14;
	float m7 = this->_m4*m._m3 + this->_m5 * m._m7 + this->_m6*m._m11 + this->_m7 * m._m15;

	float m8 = this->_m8*m._m0 + this->_m9 * m._m4 + this->_m10*m._m8 + this->_m11 * m._m12;
	float m9 = this->_m8*m._m1 + this->_m9 * m._m5 + this->_m10*m._m9 + this->_m11 * m._m13;
	float m10 = this->_m8*m._m2 + this->_m9 * m._m6 + this->_m10*m._m10 + this->_m11 * m._m14;
	float m11 = this->_m8*m._m3 + this->_m9 * m._m7 + this->_m10*m._m11 + this->_m11 * m._m15;

	float m12 = this->_m12*m._m0 + this->_m13 * m._m4 + this->_m14*m._m8 + this->_m15 * m._m12;
	float m13 = this->_m12*m._m1 + this->_m13 * m._m5 + this->_m14*m._m9 + this->_m15 * m._m13;
	float m14 = this->_m12*m._m2 + this->_m13 * m._m6 + this->_m14*m._m10 + this->_m15 * m._m14;
	float m15 = this->_m12*m._m3 + this->_m13 * m._m7 + this->_m14*m._m11 + this->_m15 * m._m15;

	return Matrix(Vect(m0, m1, m2, m3), Vect(m4, m5, m6, m7), Vect(m8, m9, m10, m11), Vect(m12, m13, m14, m15));
}

Matrix Matrix::operator*=(Matrix m)
{
	float m0 = this->_m0*m._m0 + this->_m1 * m._m4 + this->_m2*m._m8 + this->_m3 * m._m12;
	float m1 = this->_m0*m._m1 + this->_m1 * m._m5 + this->_m2*m._m9 + this->_m3 * m._m13;
	float m2 = this->_m0*m._m2 + this->_m1 * m._m6 + this->_m2*m._m10 + this->_m3 * m._m14;
	float m3 = this->_m0*m._m3 + this->_m1 * m._m7 + this->_m2*m._m11 + this->_m3 * m._m15;

	float m4 = this->_m4*m._m0 + this->_m5 * m._m4 + this->_m6*m._m8 + this->_m7 * m._m12;
	float m5 = this->_m4*m._m1 + this->_m5 * m._m5 + this->_m6*m._m9 + this->_m7 * m._m13;
	float m6 = this->_m4*m._m2 + this->_m5 * m._m6 + this->_m6*m._m10 + this->_m7 * m._m14;
	float m7 = this->_m4*m._m3 + this->_m5 * m._m7 + this->_m6*m._m11 + this->_m7 * m._m15;

	float m8 = this->_m8*m._m0 + this->_m9 * m._m4 + this->_m10*m._m8 + this->_m11 * m._m12;
	float m9 = this->_m8*m._m1 + this->_m9 * m._m5 + this->_m10*m._m9 + this->_m11 * m._m13;
	float m10 = this->_m8*m._m2 + this->_m9 * m._m6 + this->_m10*m._m10 + this->_m11 * m._m14;
	float m11 = this->_m8*m._m3 + this->_m9 * m._m7 + this->_m10*m._m11 + this->_m11 * m._m15;

	float m12 = this->_m12*m._m0 + this->_m13 * m._m4 + this->_m14*m._m8 + this->_m15 * m._m12;
	float m13 = this->_m12*m._m1 + this->_m13 * m._m5 + this->_m14*m._m9 + this->_m15 * m._m13;
	float m14 = this->_m12*m._m2 + this->_m13 * m._m6 + this->_m14*m._m10 + this->_m15 * m._m14;
	float m15 = this->_m12*m._m3 + this->_m13 * m._m7 + this->_m14*m._m11 + this->_m15 * m._m15;

	this->_m0 = m0;
	this->_m1 = m1;
	this->_m2 = m2;
	this->_m3 = m3;

	this->_m4 = m4;
	this->_m5 = m5;
	this->_m6 = m6;
	this->_m7 = m7;

	this->_m8 = m8;
	this->_m9 = m9;
	this->_m10 = m10;
	this->_m11 = m11;

	this->_m12 = m12;
	this->_m13 = m13;
	this->_m14 = m14;
	this->_m15 = m15;

	return *this;
}

float Matrix::det()
{


	float d1 = this->_m0*this->_m5*this->_m10*this->_m15 + this->_m0* this->_m6 * this->_m11 * this->_m13 + this->_m0*this->_m7 *this->_m9*this->_m14;
	float d2 = this->_m1*this->_m4 * this->_m11 * this->_m14 + this->_m1* this->_m6* this->_m8 * this->_m15 + this->_m1*this->_m7* this->_m10 * this->_m12;
	float d3 = this->_m2 * this->_m4 * this->_m9  *	this->_m15 + this->_m2  * this->_m5 *this->_m11*this->_m12 + this->_m2 * this->_m7 *this->_m8* this->_m13;
	float d4 = this->_m3* this->_m4 * this->_m10 *	this->_m13 + this->_m3 * this->_m5 *this->_m8 * this->_m14 + this->_m3* this->_m6 *this->_m9* this->_m12;
	float d5 = -(this->_m0*this->_m5* this->_m11 * this->_m14) - (this->_m0* this->_m6* this->_m9 * this->_m15) - (this->_m0* this->_m7* this->_m10 * this->_m13);
	float d6 = -(this->_m1*this->_m4* this->_m10 * this->_m15) - (this->_m1* this->_m6* this->_m11 * this->_m12) - (this->_m1* this->_m7* this->_m8 * this->_m14);
	float d7 = -(this->_m2*this->_m4* this->_m11 * this->_m13) - (this->_m2* this->_m5* this->_m8 * this->_m15) - (this->_m2* this->_m7* this->_m9 * this->_m12);
	float d8 = -(this->_m3*this->_m4* this->_m9 * this->_m14) - (this->_m3* this->_m5* this->_m10 * this->_m12) - (this->_m3* this->_m6* this->_m8 * this->_m13);

	return d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
}

void Matrix::T()
{
	float temp0 = this->_m0;
	float temp1 = this->_m4;
	float temp2 = this->_m8;
	float temp3 = this->_m12;
	float temp4 = this->_m1;
	float temp5 = this->_m5;
	float temp6 = this->_m9;
	float temp7 = this->_m13;
	float temp8 = this->_m2;
	float temp9 = this->_m6;
	float temp10 = this->_m10;
	float temp11 = this->_m14;
	float temp12 = this->_m3;
	float temp13 = this->_m7;
	float temp14 = this->_m11;
	float temp15 = this->_m15;

	this->_m0 = temp0;
	this->_m1 = temp1;
	this->_m2 = temp2;
	this->_m3 = temp3;
	this->_m4 = temp4;
	this->_m5 = temp5;
	this->_m6 = temp6;
	this->_m7 = temp7;
	this->_m8 = temp8;
	this->_m9 = temp9;
	this->_m10 = temp10;
	this->_m11 = temp11;
	this->_m12 = temp12;
	this->_m13 = temp13;
	this->_m14 = temp14;
	this->_m15 = temp15;

}

Matrix Matrix::getT()
{
	float temp0 = this->_m0;
	float temp1 = this->_m4;
	float temp2 = this->_m8;
	float temp3 = this->_m12;
	float temp4 = this->_m1;
	float temp5 = this->_m5;
	float temp6 = this->_m9;
	float temp7 = this->_m13;
	float temp8 = this->_m2;
	float temp9 = this->_m6;
	float temp10 = this->_m10;
	float temp11 = this->_m14;
	float temp12 = this->_m3;
	float temp13 = this->_m7;
	float temp14 = this->_m11;
	float temp15 = this->_m15;

	return Matrix(Vect(temp0, temp1, temp2, temp3), Vect(temp4, temp5, temp6, temp7), Vect(temp8, temp9, temp10, temp11), Vect(temp12, temp13, temp14, temp15));
}

void Matrix::inv()
{

	float temp0 = (this->m6() * this->m11() * this->m13()) - (this->m7() * this->m10() * this->m13()) + (this->m7() * this->m9() * this->m14()) - (this->m5() * this->m11() * this->m14()) - (this->m6() * this->m9() * this->m15()) + (this->m5() * this->m10() * this->m15());
	float temp1 = (this->m3() * this->m10() * this->m13()) - (this->m2() * this->m11() * this->m13()) - (this->m3() * this->m9() * this->m14()) + (this->m1() * this->m11() * this->m14()) + (this->m2() * this->m9() * this->m15()) - (this->m1() * this->m10() * this->m15());
	float temp2 = (this->m2() * this->m7() * this->m13()) - (this->m3() * this->m6() * this->m13()) + (this->m3() * this->m5() * this->m14()) - (this->m1() * this->m7() * this->m14()) - (this->m2() * this->m5() * this->m15()) + (this->m1() * this->m6() * this->m15());
	float temp3 = (this->m3() * this->m6() * this->m9()) - (this->m2() * this->m7() * this->m9()) - (this->m3() * this->m5() * this->m10()) + (this->m1() * this->m7() * this->m10()) + (this->m2() * this->m5() * this->m11()) - (this->m1() * this->m6() * this->m11());

	float temp4 = (this->m7() * this->m10() * this->m12()) - (this->m6() * this->m11() * this->m12()) - (this->m7() * this->m8() * this->m14()) + (this->m4() * this->m11() * this->m14()) + (this->m6() * this->m8() * this->m15()) - (this->m4() * this->m10() * this->m15());
	float temp5 = (this->m2() * this->m11() * this->m12()) - (this->m3() * this->m10() * this->m12()) + (this->m3() * this->m8() * this->m14()) - (this->m0() * this->m11() * this->m14()) - (this->m2() * this->m8() * this->m15()) + (this->m0() * this->m10() * this->m15());
	float temp6 = (this->m3() * this->m6() * this->m12()) - (this->m2() * this->m7() * this->m12()) - (this->m3() * this->m4() * this->m14()) + (this->m0() * this->m7() * this->m14()) + (this->m2() * this->m4() * this->m15()) - (this->m0() * this->m6() * this->m15());
	float temp7 = (this->m2() * this->m7() * this->m8()) - (this->m3() * this->m6() * this->m8()) + (this->m3() * this->m4() * this->m10()) - (this->m0() * this->m7() * this->m10()) - (this->m2() * this->m4() * this->m11()) + (this->m0() * this->m6() * this->m11());

	float temp8 = (this->m5() * this->m11() * this->m12()) - (this->m7() * this->m9() * this->m12()) + (this->m7() * this->m8() * this->m13()) - (this->m4() * this->m11() * this->m13()) - (this->m5() * this->m8() * this->m15()) + (this->m4() * this->m9() * this->m15());
	float temp9 = (this->m3() * this->m9() * this->m12()) - (this->m1() * this->m11() * this->m12()) - (this->m3() * this->m8() * this->m13()) + (this->m0() * this->m11() * this->m13()) + (this->m1() * this->m8() * this->m15()) - (this->m0() * this->m9() * this->m15());
	float temp10 = (this->m1() * this->m7() * this->m12()) - (this->m3() * this->m5() * this->m12()) + (this->m3() * this->m4() * this->m13()) - (this->m0() * this->m7() * this->m13()) - (this->m1() * this->m4() * this->m15()) + (this->m0() * this->m5() * this->m15());
	float temp11 = (this->m3() * this->m5() * this->m8()) - (this->m1() * this->m7() * this->m8()) - (this->m3() * this->m4() * this->m9()) + (this->m0() * this->m7() * this->m9()) + (this->m1() * this->m4() * this->m11()) - (this->m0() * this->m5() * this->m11());

	float temp12 = (this->m6() * this->m9() * this->m12()) - (this->m5() * this->m10() * this->m12()) - (this->m6() * this->m8() * this->m13()) + (this->m4() * this->m10() * this->m13()) + (this->m5() * this->m8() * this->m14()) - (this->m4() * this->m9() * this->m14());
	float temp13 = (this->m1() * this->m10() * this->m12()) - (this->m2() * this->m9() * this->m12()) + (this->m2() * this->m8() * this->m13()) - (this->m0() * this->m10() * this->m13()) - (this->m1() * this->m8() * this->m14()) + (this->m0() * this->m9() * this->m14());
	float temp14 = (this->m2() * this->m5() * this->m12()) - (this->m1() * this->m6() * this->m12()) - (this->m2() * this->m4() * this->m13()) + (this->m0() * this->m6() * this->m13()) + (this->m1() * this->m4() * this->m14()) - (this->m0() * this->m5() * this->m14());
	float temp15 = (this->m1() * this->m6() * this->m8()) - (this->m2() * this->m5() * this->m8()) + (this->m2() * this->m4() * this->m9()) - (this->m0() * this->m6() * this->m9()) - (this->m1() * this->m4() * this->m10()) + (this->m0() * this->m5() * this->m10());

	Matrix temp = Matrix(Vect(temp0, temp1, temp2, temp3), Vect(temp4, temp5, temp6, temp7), Vect(temp8, temp9, temp10, temp11), Vect(temp12, temp13, temp14, temp15));
	temp *= 1 / (this->det());


	*this = temp;
}

Matrix Matrix::getInv()
{
	float temp0 = (this->m6() * this->m11() * this->m13()) - (this->m7() * this->m10() * this->m13()) + (this->m7() * this->m9() * this->m14()) - (this->m5() * this->m11() * this->m14()) - (this->m6() * this->m9() * this->m15()) + (this->m5() * this->m10() * this->m15());
	float temp1 = (this->m3() * this->m10() * this->m13()) - (this->m2() * this->m11() * this->m13()) - (this->m3() * this->m9() * this->m14()) + (this->m1() * this->m11() * this->m14()) + (this->m2() * this->m9() * this->m15()) - (this->m1() * this->m10() * this->m15());
	float temp2 = (this->m2() * this->m7() * this->m13()) - (this->m3() * this->m6() * this->m13()) + (this->m3() * this->m5() * this->m14()) - (this->m1() * this->m7() * this->m14()) - (this->m2() * this->m5() * this->m15()) + (this->m1() * this->m6() * this->m15());
	float temp3 = (this->m3() * this->m6() * this->m9()) - (this->m2() * this->m7() * this->m9()) - (this->m3() * this->m5() * this->m10()) + (this->m1() * this->m7() * this->m10()) + (this->m2() * this->m5() * this->m11()) - (this->m1() * this->m6() * this->m11());

	float temp4 = (this->m7() * this->m10() * this->m12()) - (this->m6() * this->m11() * this->m12()) - (this->m7() * this->m8() * this->m14()) + (this->m4() * this->m11() * this->m14()) + (this->m6() * this->m8() * this->m15()) - (this->m4() * this->m10() * this->m15());
	float temp5 = (this->m2() * this->m11() * this->m12()) - (this->m3() * this->m10() * this->m12()) + (this->m3() * this->m8() * this->m14()) - (this->m0() * this->m11() * this->m14()) - (this->m2() * this->m8() * this->m15()) + (this->m0() * this->m10() * this->m15());
	float temp6 = (this->m3() * this->m6() * this->m12()) - (this->m2() * this->m7() * this->m12()) - (this->m3() * this->m4() * this->m14()) + (this->m0() * this->m7() * this->m14()) + (this->m2() * this->m4() * this->m15()) - (this->m0() * this->m6() * this->m15());
	float temp7 = (this->m2() * this->m7() * this->m8()) - (this->m3() * this->m6() * this->m8()) + (this->m3() * this->m4() * this->m10()) - (this->m0() * this->m7() * this->m10()) - (this->m2() * this->m4() * this->m11()) + (this->m0() * this->m6() * this->m11());

	float temp8 = (this->m5() * this->m11() * this->m12()) - (this->m7() * this->m9() * this->m12()) + (this->m7() * this->m8() * this->m13()) - (this->m4() * this->m11() * this->m13()) - (this->m5() * this->m8() * this->m15()) + (this->m4() * this->m9() * this->m15());
	float temp9 = (this->m3() * this->m9() * this->m12()) - (this->m1() * this->m11() * this->m12()) - (this->m3() * this->m8() * this->m13()) + (this->m0() * this->m11() * this->m13()) + (this->m1() * this->m8() * this->m15()) - (this->m0() * this->m9() * this->m15());
	float temp10 = (this->m1() * this->m7() * this->m12()) - (this->m3() * this->m5() * this->m12()) + (this->m3() * this->m4() * this->m13()) - (this->m0() * this->m7() * this->m13()) - (this->m1() * this->m4() * this->m15()) + (this->m0() * this->m5() * this->m15());
	float temp11 = (this->m3() * this->m5() * this->m8()) - (this->m1() * this->m7() * this->m8()) - (this->m3() * this->m4() * this->m9()) + (this->m0() * this->m7() * this->m9()) + (this->m1() * this->m4() * this->m11()) - (this->m0() * this->m5() * this->m11());

	float temp12 = (this->m6() * this->m9() * this->m12()) - (this->m5() * this->m10() * this->m12()) - (this->m6() * this->m8() * this->m13()) + (this->m4() * this->m10() * this->m13()) + (this->m5() * this->m8() * this->m14()) - (this->m4() * this->m9() * this->m14());
	float temp13 = (this->m1() * this->m10() * this->m12()) - (this->m2() * this->m9() * this->m12()) + (this->m2() * this->m8() * this->m13()) - (this->m0() * this->m10() * this->m13()) - (this->m1() * this->m8() * this->m14()) + (this->m0() * this->m9() * this->m14());
	float temp14 = (this->m2() * this->m5() * this->m12()) - (this->m1() * this->m6() * this->m12()) - (this->m2() * this->m4() * this->m13()) + (this->m0() * this->m6() * this->m13()) + (this->m1() * this->m4() * this->m14()) - (this->m0() * this->m5() * this->m14());
	float temp15 = (this->m1() * this->m6() * this->m8()) - (this->m2() * this->m5() * this->m8()) + (this->m2() * this->m4() * this->m9()) - (this->m0() * this->m6() * this->m9()) - (this->m1() * this->m4() * this->m10()) + (this->m0() * this->m5() * this->m10());

	Matrix temp = Matrix(Vect(temp0, temp1, temp2, temp3), Vect(temp4, temp5, temp6, temp7), Vect(temp8, temp9, temp10, temp11), Vect(temp12, temp13, temp14, temp15));
	temp *= 1 / (this->det());
	return temp;
}

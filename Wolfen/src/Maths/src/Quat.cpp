//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 
#include "wfpch.h"
#include <math.h>
#include <assert.h>

#include "Maths/include/MathEngine.h"

// Do your magic here


Quat::Quat(const Vect& v, float w ) {
	this->_qx = v[x];
	this->_qy = v[y];
	this->_qz = v[z];
	this->_qw = w;
}

Quat::Quat(const Matrix& M ) {
	float tr = M[m0] + M[m5] + M[m10];
	float S;
	if (tr > 0.0f)
	{
		S = 2 * sqrtf(tr + 1.0f);
		this->_qw = 0.25f * S;
		this->_qx = -(M[m9] - M[m6]) / S;
		this->_qy = -(M[m2] - M[m8]) / S;
		this->_qz = -(M[m4] - M[m1]) / S;
	}
	else if((M[m0] > M[m5]) && (M[m0] > M[m10]))
	{
		S = 2 * sqrtf(1.0f + M[m0] - M[m5] - M[m10]);
		this->_qw = -(M[m9] - M[m6]) / S;
		this->_qx = 0.25f * S;
		this->_qy = (M[m1] + M[m4]) / S;
		this->_qz = (M[m2] + M[m8]) / S;
	}
	else if(M[m5] > M[m10])
	{
		S = 2 * sqrtf(1.0f + M[m5] - M[m0] - M[m10]);
		this->_qw = -(M[m2] - M[m8]) / S;
		this->_qx = (M[m1] + M[m4]) / S;
		this->_qy = 0.25f * S;
		this->_qz = (M[m6] + M[m9]) / S;
	}
	else
	{
		S = 2 * sqrtf(1.0f + M[m10] - M[m0] - M[m5]);
		this->_qw = -(M[m4] - M[m1]) / S;
		this->_qx = (M[m2] + M[m8]) / S;
		this->_qy = (M[m6] + M[m9]) / S;
		this->_qz = 0.25f * S;
	}
	
}

Quat& Quat::operator=(const Quat & q)
{
	this->_qx = q[x];
	this->_qy = q[y];
	this->_qz = q[z];
	this->_qw = q[w];

	return *this;
}

Quat & Quat::operator=(const Matrix & M)
{
	float tr = M[m0] + M[m5] + M[m10];
	float S;

	if (tr > 0.0f)
	{
		S = 2 * sqrtf(tr + 1.0f);
		this->_qw = 0.25f * S;
		this->_qx = -(M[m9] - M[m6]) / S;
		this->_qy = -(M[m2] - M[m8]) / S;
		this->_qz = -(M[m4] - M[m1]) / S;
	}
	else if ((M[m0] > M[m5]) && (M[m0] > M[m10]))
	{
		S = 2 * sqrtf(1.0f + M[m0] - M[m5] - M[m10]);
		this->_qw = -(M[m9] - M[m6]) / S;
		this->_qx = 0.25f * S;
		this->_qy = (M[m1] + M[m4]) / S;
		this->_qz = (M[m2] + M[m8]) / S;
	}
	else if (M[m5] > M[m10])
	{
		S = 2 * sqrtf(1.0f + M[m5] - M[m0] - M[m10]);
		this->_qw = -(M[m2] - M[m8]) / S;
		this->_qx = (M[m1] + M[m4]) / S;
		this->_qy = 0.25f * S;
		this->_qz = (M[m6] + M[m9]) / S;
	}
	else
	{
		S = 2 * sqrtf(1.0f + M[m10] - M[m0] - M[m5]);
		this->_qw = -(M[m4] - M[m1]) / S;
		this->_qx = (M[m2] + M[m8]) / S;
		this->_qy = (M[m6] + M[m9]) / S;
		this->_qz = 0.25f * S;
	}


	return *this;
}

Quat::Quat(const Quat & q)
{
	this->_qx = q[x];
	this->_qy = q[y];
	this->_qz = q[z];
	this->_qw = q[w];
}


float Quat::operator[](x_enum) const
{
	return this->_qx;
}

float Quat::operator[](y_enum) const
{
	return this->_qy;
}

float Quat::operator[](z_enum) const
{
	return this->_qz;
}

float Quat::operator[](w_enum) const
{
	return this->_qw;
}

float & Quat::operator[](x_enum)
{
	return this->_qx;
}

float & Quat::operator[](y_enum)
{
	return this->_qy;
}

float & Quat::operator[](z_enum)
{
	return this->_qz;
}

float & Quat::operator[](w_enum)
{
	return this->_qw;
}

float Quat::qx() const
{
	return this->_qx;
}

float Quat::qy() const
{
	return this->_qy;
}

float Quat::qz() const
{
	return this->_qz;
}

float Quat::real() const
{
	return this->_qw;
}

float & Quat::qx()
{
	return this->_qx;
}

float & Quat::qy()
{
	return this->_qy;
}

float & Quat::qz()
{
	return this->_qz;
}

float & Quat::real()
{
	return this->_qw;
}

void Quat::set(float x, float y, float z, float w)
{
	this->_qx = x;
	this->_qy = y;
	this->_qz = z;
	this->_qw = w;
}

void Quat::set(Matrix M)
{
	float tr = M[m0] + M[m5] + M[m10];
	float S;
	if (tr > 0.0f)
	{
		S = 2 * sqrtf(tr + 1.0f);
		this->_qw = 0.25f * S;
		this->_qx = -(M[m9] - M[m6]) / S;
		this->_qy = -(M[m2] - M[m8]) / S;
		this->_qz = -(M[m4] - M[m1]) / S;
	}
	else if ((M[m0] > M[m5]) && (M[m0] > M[m10]))
	{
		S = 2 * sqrtf(1.0f + M[m0] - M[m5] - M[m10]);
		this->_qw = -(M[m9] - M[m6]) / S;
		this->_qx = 0.25f * S;
		this->_qy = (M[m1] + M[m4]) / S;
		this->_qz = (M[m2] + M[m8]) / S;
	}
	else if (M[m5] > M[m10])
	{
		S = 2 * sqrtf(1.0f + M[m5] - M[m0] - M[m10]);
		this->_qw = -(M[m2] - M[m8]) / S;
		this->_qx = (M[m1] + M[m4]) / S;
		this->_qy = 0.25f * S;
		this->_qz = (M[m6] + M[m9]) / S;
	}
	else
	{
		S = 2 * sqrtf(1.0f + M[m10] - M[m0] - M[m5]);
		this->_qw = -(M[m4] - M[m1]) / S;
		this->_qx = (M[m2] + M[m8]) / S;
		this->_qy = (M[m6] + M[m9]) / S;
		this->_qz = 0.25f * S;
	}
	//float tr = M[m0] + M[m5] + M[m10];
	//float S;
	//if (tr > 0.0f)
	//{
	//	S = 2 * sqrtf(tr + 1.0f);
	//	this->_qw = 0.25f * S;
	//	this->_qx = (M[m9] - M[m6]) / S;
	//	this->_qy = (M[m2] - M[m8]) / S;
	//	this->_qz = (M[m4] - M[m1]) / S;
	//}
	//else if ((M[m0] > M[m5]) && (M[m0] > M[m10]))
	//{
	//	S = 2 * sqrtf(1.0f + M[m0] - M[m5] - M[m10]);
	//	this->_qw = (M[m9] - M[m6]) / S;
	//	this->_qx = 0.25f * S;
	//	this->_qy = (M[m1] + M[m4]) / S;
	//	this->_qz = (M[m2] + M[m8]) / S;
	//}
	//else if (M[m5] > M[m10])
	//{
	//	S = 2 * sqrtf(1.0f + M[m5] - M[m0] - M[m10]);
	//	this->_qw = (M[m2] - M[m8]) / S;
	//	this->_qx = (M[m1] + M[m4]) / S;
	//	this->_qy = 0.25f * S;
	//	this->_qz = (M[m6] + M[m9]) / S;
	//}
	//else
	//{
	//	S = 2 * sqrtf(1.0f + M[m10] - M[m0] - M[m5]);
	//	this->_qw = (M[m4] - M[m1]) / S;
	//	this->_qx = (M[m2] + M[m8]) / S;
	//	this->_qy = (M[m6] + M[m9]) / S;
	//	this->_qz = 0.25f * S;
	//}


}

void Quat::set(Vect & v, float w)
{
	this->_qx = v[x];
	this->_qy = v[y];
	this->_qz = v[z];
	this->_qw = w;
}

void Quat::setVect(const Vect & v)
{
	this->_qx = v[x];
	this->_qy = v[y];
	this->_qz = v[z];
	this->_qw = 0;
}

void Quat::getVect( Vect& v)
{
	v.set(this->_qx,this->_qy, this->_qz);
}

Quat::Quat(Quat::SpecialType type)
{
	if (type == Quat::SpecialType::Identity) {
		this->_qx = 0;
		this->_qy = 0;
		this->_qz = 0;
		this->_qw = 1;
	}

	else if (type == Quat::SpecialType::Zero) {
		this->_qx = 0;
		this->_qy = 0;
		this->_qz = 0;
		this->_qw = 0;
	}
}

void Quat::set(Quat::SpecialType type)
{
	if (type == Quat::SpecialType::Identity) {
		this->_qx = 0;
		this->_qy = 0;
		this->_qz = 0;
		this->_qw = 1;
	}

	else if (type == Quat::SpecialType::Zero) {
		this->_qx = 0;
		this->_qy = 0;
		this->_qz = 0;
		this->_qw = 0;
	}
}

Quat::Quat(Quat::RotType type, float theta)
{
	Matrix m;
	if (type == Quat::Rot_X) {
		m = Matrix(Matrix::RotType::Rot_X, theta);
		this->set(m);
	}

	else if (type == Quat::Rot_Y) {
		m = Matrix(Matrix::RotType::Rot_Y, theta);
		this->set(m);
	}

	else if (type == Quat::Rot_Z) {
		m = Matrix(Matrix::RotType::Rot_Z, theta);
		this->set(m);
	}
}

void Quat::set(Quat::RotType type, float theta)
{
	Matrix m;
	if (type == Quat::Rot_X) {
		m = Matrix(Matrix::RotType::Rot_X, theta);
		this->set(m);
	}

	else if (type == Quat::Rot_Y) {
		m = Matrix(Matrix::RotType::Rot_Y, theta);
		this->set(m);
	}

	else if (type == Quat::Rot_Z) {
		m = Matrix(Matrix::RotType::Rot_Z, theta);
		this->set(m);
	}
}

Quat::Quat(Quat::RotAxisAngleType,Vect v, float theta)
{
	Vect n = v.getNorm();

	float angle = sinf(theta / 2.0f);

	Quat q(n[x] * angle, n[y] * angle, n[z] * angle, cosf(theta / 2.0f));
	//q = q* 0.5f;
	//float angle = 2.0f * acosf(theta);

	*this = q;
}

void Quat::set(Quat::RotAxisAngleType, Vect v, float theta)
{
	Vect n = v.getNorm();

	float angle = sinf(theta / 2.0f);

	Quat q(n[x] * angle, n[y] * angle, n[z] * angle, cosf(theta / 2.0f));
	//q = q* 0.5f;
	//float angle = 2.0f * acosf(theta);

	*this = q;
}

Quat::Quat(Quat::RotOrientType type, Vect vUp, Vect vDir)
{
	Matrix m(*this);

	if (type == Quat::RotOrientType::RotOrient) {
		m.set(Matrix::RotOrientType::RotOrient, vUp, vDir);
	}
	else {
		m.set(Matrix::RotOrientType::RotInverseOrient, vUp, vDir);
	}

	*this = m;
}

void Quat::set(Quat::RotOrientType type, Vect vUp, Vect vDir)
{
	Matrix m(*this);

	if (type == Quat::RotOrientType::RotOrient) {
		m.set(Matrix::RotOrientType::RotOrient, vUp, vDir);
	}
	else {
		m.set(Matrix::RotOrientType::RotInverseOrient, vUp, vDir);
	}

	*this = m;
}

Quat::Quat(Quat::Rot3AngleType, float x, float y, float z)
{
	
	Quat rotx = Quat(Quat::RotType::Rot_X, x);
	Quat roty = Quat(Quat::RotType::Rot_Y, y);
	Quat rotz = Quat(Quat::RotType::Rot_Z, z);

	*this = rotx * roty *rotz;
	//float sx = sinf(x / 2.0f);
	//float sy = sinf(y / 2.0f);
	//float sz = sinf(z / 2.0f);

	//float cx = sinf(x / 2.0f);
	//float cy = sinf(y / 2.0f);
	//float cz = sinf(z / 2.0f);


	//this->_qx = (sx * cy * cz) + (cx * sy * sz);
	//this->_qy = (cx * sy * cz) - (sx * cy * sz);
	//this->_qz = (sx * sy * cz) + (cx * cy * sz);
	//this->_qw = (cx * cy * cz) - (sx * sy * sz);
}

void Quat::set(Quat::Rot3AngleType, const float x, const float y, const float z)
{
	Quat rotx = Quat(Quat::RotType::Rot_X, x);
	Quat roty = Quat(Quat::RotType::Rot_Y, y);
	Quat rotz = Quat(Quat::RotType::Rot_Z, z);

	//float sx = sinf(x / 2.0f);
	//float sy = sinf(y / 2.0f);
	//float sz = sinf(z / 2.0f);

	//float cx = sinf(x / 2.0f);
	//float cy = sinf(y / 2.0f);
	//float cz = sinf(z / 2.0f);


	//this->_qx = (sx * cy * cz) + (cx * sy * sz);
	//this->_qy = (cx * sy * cz) - (sx * cy * sz);
	//this->_qz = (sx * sy * cz) + (cx * cy * sz);
	//this->_qw = (cx * cy * cz) - (sx * sy * sz);



	*this = rotx * roty *rotz;
}


bool Quat::isEqual(Quat q, float epsilon)
{

	return (Util::isEqual(this->_qx, q._qx, epsilon) && Util::isEqual(this->_qy, q._qy, epsilon) && Util::isEqual(this->_qz, q._qz, epsilon) && Util::isEqual(this->_qw,q._qw,epsilon));
}

bool Quat::isNegEqual(Quat q, float epsilon)
{
	return (Util::isEqual(this->_qx, -q._qx, epsilon) && Util::isEqual(this->_qy, -q._qy, epsilon) && Util::isEqual(this->_qz, -q._qz, epsilon) && Util::isEqual(this->_qw, -q._qw, epsilon));
}


bool Quat::isIdentity(float epsilon)
{
	return (Util::isEqual(this->_qx, 0, epsilon) && Util::isEqual(this->_qy, 0, epsilon) && Util::isEqual(this->_qz, 0, epsilon) && Util::isEqual(this->_qw, 1, epsilon));
}

bool Quat::isEquivalent(Quat q, float epsilon)
{
	return this->isNegEqual(q,epsilon) || this->isEqual(q,epsilon);
}

bool Quat::isConjugateEqual(Quat q, float epsilon)
{
	return this->getConj().isEqual(q,epsilon);
}

bool Quat::isNormalized(float epsilon)
{
	Quat norm = this->getNorm();
	return this->isEqual(norm, epsilon);
}

bool Quat::isZero(float epsilon)
{
	return  (Util::isEqual(this->_qx, 0, epsilon) && Util::isEqual(this->_qy, 0, epsilon) && Util::isEqual(this->_qz, 0, epsilon) && Util::isEqual(this->_qw, 0, epsilon));
}

Quat Quat::operator*(Quat& q2)
{
	//calculate scalar and vector components
	Vect p = Vect(this->_qx, this->_qy, this->_qz);
	Vect qv = Vect(q2._qx, q2._qy, q2._qz);


		//scalar
	float scalar = (this->_qw* q2._qw) - p.dot(qv);

		//vector
	Vect tempV = qv.cross(p) + (q2._qw*p) + (this->_qw*qv);

	return Quat(tempV,scalar);

}

void Quat::operator*=(Quat q2)
{
	//calculate scalar and vector components
	Vect p = Vect(this->_qx, this->_qy, this->_qz);
	Vect qv = Vect(q2._qx, q2._qy, q2._qz);


	//scalar
	float scalar = (this->_qw* q2._qw) - p.dot(qv);

	//vector
	Vect tempV = qv.cross(p) + (q2._qw*p) + (this->_qw*qv);

	*this = Quat(tempV, scalar);
}

Matrix Quat::operator*(Matrix m)
{
	Matrix tmp(*this);
	return tmp * m;
}

void Quat::operator*=(Matrix m){
	//Quat temp;
	//Quat qm(m);
	//temp = *this * qm;
	Matrix tmp(*this);
	tmp = tmp * m;
	Quat temp(tmp);
	*this = temp;
}

Quat Quat::multByElement(const Quat& q)
{
	return Quat(this->_qx * q._qx, this->_qy * q._qy, this->_qz * q._qz, this->_qw * q._qw);
}

Quat Quat::operator/(const Quat& q)
{
	return Quat(this->_qx / q._qx, this->_qy / q._qy, this->_qz / q._qz, this->_qw / q._qw);
}

void Quat::operator /=(const Quat& q)
{
	this->_qx /= q._qx;
	this->_qy /= q._qy;
	this->_qz /= q._qz;
	this->_qw /= q._qw;
}

Quat Quat::operator/(const float f)
{
	return Quat(this->_qx / f, this->_qy / f, this->_qz / f, this->_qw / f);
}

void Quat::operator/=(const float f)
{
	this->_qx /= f;
	this->_qy /= f;
	this->_qz /= f;
	this->_qw /= f;
}

Quat Quat::operator+()
{
	return Quat(this->_qx, this->_qy, this->_qz, this->_qw);
}

const Quat Quat::operator+(const Quat& q) const
{
	return Quat(this->_qx + q._qx,this->_qy + q._qy,this->_qz + q._qz,this->_qw + q._qw);
}

void Quat::operator+=(const Quat& q)
{
	this->_qx += q._qx;
	this->_qy += q._qy;
	this->_qz += q._qz;
	this->_qw += q._qw;
}

const Quat Quat::operator+(const float f) const
{
	return Quat(this->_qx +f, this->_qy +f, this->_qz + f, this->_qw + f);
}

void Quat::operator+=(const float f)
{
	this->_qx += f;
	this->_qy += f;
	this->_qz += f;
	this->_qw += f;
}

Quat Quat::operator-()
{
	return Quat(-this->_qx, -this->_qy, -this->_qz, -this->_qw);
}

Quat Quat::operator-(const Quat& q)
{
	return Quat(this->_qx - q._qx, this->_qy - q._qy, this->_qz - q._qz, this->_qw - q._qw);
}

void Quat::operator-=(const Quat& q)
{
	this->_qx -= q._qx;
	this->_qy -= q._qy;
	this->_qz -= q._qz;
	this->_qw -= q._qw;
}

Quat Quat::operator-(const float f)
{
	return Quat(this->_qx - f, this->_qy - f, this->_qz - f, this->_qw - f);
}

void Quat::operator-=(const float f)
{
	this->_qx -= f;
	this->_qy -= f;
	this->_qz -= f;
	this->_qw -= f;
}

const Quat Quat::operator*(const float s) const
{
	return Quat(this->_qx * s, this->_qy * s, this->_qz * s, this->_qw * s);
}

void Quat::operator*=(const float s)
{
	this->_qx *= s;
	this->_qy *= s;
	this->_qz *= s;
	this->_qw *= s;
}

Quat operator+(const float f, const Quat& q)
{
	return Quat(q._qx + f, q._qy + f, q._qz + f, q._qw + f);
}

Quat operator-(const float f, const Quat& q)
{
	return Quat(f - q._qx,  f - q._qy ,f -  q._qz, f - q._qw );
}

Quat operator*(const float f, const Quat& q)
{
	return Quat(f * q._qx, f * q._qy, f * q._qz, f * q._qw);
}

Quat operator/(const float f, const Quat& q)
{
	return Quat(f / q._qx, f / q._qy, f / q._qz, f / q._qw);
}


Quat Quat::getConj()
{

	Vect v = Vect(-this->_qx, -this->_qy, -this->_qz);
	//v = (-v) + this->_qw;

	return Quat(v, this->_qw);
}


void Quat::conj() {
	this->_qx = -this->_qx;
	this->_qy = -this->_qy;
	this->_qz = -this->_qz;
}

Quat Quat::getT()
{
	return Quat(-this->_qx, -this->_qy, -this->_qz, this->_qw);
}

void Quat::T()
{
	this->_qx = -this->_qx;
	this->_qy = -this->_qy;
	this->_qz = -this->_qz;
}

float Quat::mag()
{
	return sqrtf(this->_qx*this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw);
}


float Quat::magSquared()
{
	return this->_qx*this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw;
}


float Quat::invMag()
{
	return 1.0f / sqrtf(this->_qx*this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw);
}

float Quat::invMagSquared()
{
	return 1.0f / (this->_qx*this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw);
}

Quat Quat::norm() {
	*this = *this * invMag();

	return *this;
}


Quat Quat::getNorm() {
	return Quat(*this * this->invMag());
}

Quat Quat::getInv()
{
	return Quat(this->getConj() * this->invMagSquared());
}

Quat Quat::inv()
{
	*this = Quat(this->getConj() * this->invMagSquared());
	
	return *this;
}

void Quat::Lqcvq(Vect vIn, Vect & vOut)
{
	Vect temp(this->_qx, this->_qy, this->_qz);//, this->_qw);
	float w = this->_qw;

	vOut = 2.0f * w *(temp.cross(vIn)) + vIn * (w * w - temp.dot(temp)) + 2 * (temp.dot(vIn)) * temp;

}

void Quat::Lqvqc(Vect vIn, Vect & vOut)
{
	Vect temp(this->_qx, this->_qy, this->_qz);//, this->_qw);
	float w = this->_qw;
	vOut = 2.0f * w *(vIn.cross(temp)) + vIn * (w * w - temp.dot(temp)) + 2 * (temp.dot(vIn)) * temp;
}

float Quat::dot(const Quat& q) const
{
	return 	this->_qx * q._qx + this->_qy * q._qy + this->_qz * q._qz + this->_qw * q._qw;
	
}

float Quat::getAngle()
{
	return 2.0f * (acosf(this->_qw));
}

void Quat::getAxis(Vect & v)
{
	v[x] = this->_qx;
	v[y] = this->_qy;
	v[z] = this->_qz;
	v[w] = 1.0f;


}

// ---  End of File ---------------

//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_QUAT_H
#define ENGINE_MATH_QUAT_H

#include "Matrix.h"

//------------------------------------------------------------------------
// 
//  This class contains functions and data structure for a 4-dimensional
//  Quaternions.  The quaternions are internally stored interms of the
//  imaginary components (x,y,z) and the real components (real).
// 
//  In the Math library, quaternions can be thought of as "rotational"
//  matrices, everything that you can represent with rotational matrices
//  you can use with quaternions.  Such as quaternion concatenation,
//  inverses, transpose, normalize, multiplying with matrices, and with
//  vectors.
// 
//------------------------------------------------------------------------

class Quat final : public Align16
{
public:
	enum RotType
	{
		Rot_X,
		Rot_Y,
		Rot_Z
	};

	enum SpecialType
	{
		Zero,
		Identity
	};

	enum RotAxisAngleType
	{
		RotAxisAngle
	};

	enum RotOrientType
	{
		RotOrient,
		RotInverseOrient
	};

	enum Rot3AngleType
	{
		Rot_XYZ
		// future combos... here
	};

public:

	// Do your magic here

private:

	// anonymous union
	union
	{
		__m128	_mq;

		// anonymous struct
		struct
		{
			float _qx;
			float _qy;
			float _qz;
			float _qw;
		};
	};
	
public:

	//constructors
	Quat(float x = 0, float y = 0, float z = 0, float w = 1) :_qx(x), _qy(y), _qz(z), _qw(w) {};
	Quat(const Vect& v, float w = 1);
	Quat(const Matrix& m);

	Quat & operator = (const Quat& q);
	Quat & operator = (const Matrix& m);

	Quat(const Quat& q);

	//accessors
	float operator[](x_enum) const;
	float operator[](y_enum) const;
	float operator[](z_enum) const;
	float operator[](w_enum) const;
	float& operator[](x_enum);
	float& operator[](y_enum);
	float& operator[](z_enum);
	float& operator[](w_enum);

	float qx() const;
	float qy() const;
	float qz() const;
	float real() const;
	float & qx();
	float & qy();
	float & qz();
	float & real();

	//setters
	void set(float x = 0, float y = 0, float z = 0, float w = 1);
	void set(Matrix M);
	void set(Vect& v, float w = 1);

	void setVect(const Vect& v);
	void getVect( Vect& v);

	//special matrices
	Quat(Quat::SpecialType type);
	void set(Quat::SpecialType type);

	//rotation
	Quat(Quat::RotType type, float theta);
	void set(Quat::RotType type, float theta);

	Quat(Quat::RotAxisAngleType, Vect v, float theta);
	void set(Quat::RotAxisAngleType, Vect v, float theta);

	Quat(Quat::RotOrientType type, Vect vUp, Vect vDir);
	void set(Quat::RotOrientType type, Vect vUp, Vect vDir);

	Quat(Quat::Rot3AngleType, float x, float y, float z);
	void set(Quat::Rot3AngleType, float x, float y, float z);


	//booleans
	bool isEqual(Quat q, float epsilon = MATH_TOLERANCE);
	bool isNegEqual(Quat q, float epsilon = MATH_TOLERANCE);
	bool isIdentity(float epsilon = MATH_TOLERANCE);
	bool isEquivalent(Quat q, float epsilon = MATH_TOLERANCE);
	bool isConjugateEqual(Quat q, float epsilon = MATH_TOLERANCE);
	bool isNormalized(float epsilon = MATH_TOLERANCE);
	bool isZero(float epsilon = MATH_TOLERANCE);


	//operations
	Quat operator+();
	const Quat operator+ (const Quat& q) const;
	void operator +=(const Quat& q);

	const Quat  operator+(const float f) const;
	void operator+=(const float f);
	friend Quat operator +(const float f, const Quat& q);

	Quat operator-();
	Quat operator -(const Quat& q);
	void operator -=(const Quat& q);

	Quat operator-(const float f);
	void operator-=(const float f);
	friend Quat operator -(const float f, const Quat& q);


	const Quat operator *(const float s) const;
	void operator *=(const float s);

	Quat operator*(Quat& q2);
	void operator*=(Quat q2);
	friend Quat operator *(const float f, const Quat& q);

	Matrix operator*(Matrix m);
	void operator*=(Matrix m);

	Quat multByElement(const Quat& q);
	//Quat operator*(Vect v);

	Quat operator / (const Quat& q);
	void operator /= (const Quat& q);

	Quat operator /(const float f);
	void operator /=(const float f);
	friend Quat operator /(const float f, const Quat& q);

	// vector like operations

	Quat getConj();
	void conj();

	Quat getT();
	void T();

	float mag();
	float magSquared();
	float invMag();
	float invMagSquared();

	Quat norm();
	Quat getNorm();

	Quat getInv();
	Quat inv();
	

	void Lqcvq(Vect vIn, Vect& vOut);
	void Lqvqc(Vect vIn, Vect& vOut);

	float dot(const Quat& q) const;

	float getAngle();

	void getAxis(Vect& v);

	//Quat cross(Quat q);
	//float dot(Vect v);
	//Quat cross(Vect v);
	//void norm();
	//Vect getNorm();
	//float mag();
	//float magSqr();
	//float getAngle(Vect v);
};


#endif 

// ---  End of File ---------------

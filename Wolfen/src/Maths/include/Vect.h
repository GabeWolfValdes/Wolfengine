//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h>

#include "Align16.h"
#include "Constants.h"
#include "Enum.h"

// forward declare
class Matrix;
class Quat;

class Vect final : public Align16
{
public:
 
	// Do your magic here

private:

	union 
	{
		__m128	_mv;

		// anonymous struct
		struct 
			{
			float _vx;
			float _vy;
			float _vz;
			float _vw;
			};
	};
public:
	//functions


	//INITIALIZATION-------------------------------
	Vect(float x = 0, float y = 0, float z = 0, float w = 1) :_vx(x), _vy(y), _vz(z), _vw(w) {};


	//SET ------------------------------------
	float operator[](x_enum) const;
	float operator[](y_enum) const;
	float operator[](z_enum) const;
	float operator[](w_enum) const;
	float& operator[](x_enum);
	float& operator[](y_enum);
	float& operator[](z_enum);
	float& operator[](w_enum);
	void set(float x = 0, float y = 0, float z = 0, float w = 1);
	void set(Vect vect);


	//GET ------------------------------------
	float x() const;
	float y() const;
	float z() const;
	float w() const;
	float & x();
	float & y();
	float & z();
	float & w();


	//Math operators
	Vect operator +(const Vect& v)const;
	void operator +=(const Vect& v);
	void MatrixAdd(const Vect& v);

	Vect operator -(const Vect v) const;
	void operator -=(const Vect& v) ;
	void MatrixSub(const Vect& v);

	Vect operator *(const float s) const;
	void operator *=(const float s);
	void MatrixScale(const float s);


	Vect operator +();
	Vect operator -();
	friend Vect operator *(float s, const Vect& v);

	//bool ops
	bool isEqual(Vect v, const float epsilon = MATH_TOLERANCE);
	bool isZero(const float epsilon = MATH_TOLERANCE);

	//common vect functions
	float dot(const Vect& v);
	Vect cross(const Vect& v) const;
	void norm();
	Vect getNorm() const;
	float mag();
	float magSqr();
	float getAngle(const Vect& v);

	//vect and matrix functions
	Vect operator *(const Matrix& m)const;
	Vect operator *=(const Matrix& m);
};


#endif

// ---  End of File ---------------

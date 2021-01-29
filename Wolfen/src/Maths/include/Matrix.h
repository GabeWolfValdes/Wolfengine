//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

#include "Vect.h"

class Quat;


class Matrix final : public Align16
{
public:
	enum SpecialType
	{
		Zero,
		Identity
	};

	enum RotType
	{
		Rot_X,
		Rot_Y,
		Rot_Z
	};

	enum TransType
	{
		Trans
	};

	enum ScaleType
	{
		Scale
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

	enum RowType
	{
		Row_0,
		Row_1,
		Row_2,
		Row_3
	};


	enum Rot3AngleType
	{
		Rot_XYZ
		// future combos... here
	};

public:

	// Do your magic here
 
private: 

	union
	{
		struct
		{
			Vect _v0;
			Vect _v1;
			Vect _v2;
			Vect _v3;
		};

		struct
		{
			float _m0;
			float _m1;
			float _m2;
			float _m3;
			float _m4;
			float _m5;
			float _m6;
			float _m7;
			float _m8;
			float _m9;
			float _m10;
			float _m11;
			float _m12;
			float _m13;
			float _m14;
			float _m15;
		};
	};

public:
	//FUNCTIONS

	//constructors + destructor
	//default
	Matrix();

	//with Vects
	Matrix(Vect v0, Vect v1, Vect v2, Vect v3);
	Matrix & operator = (const Matrix &m); //<-- works somehow without explicit call
	Matrix(Quat q);


	//Getters/ Setters
	float& operator[] (m0_enum) { return this->_m0; };
	float& operator[] (m1_enum) { return this->_m1; };
	float& operator[] (m2_enum) { return this->_m2; };
	float& operator[] (m3_enum) { return this->_m3; };
	float& operator[] (m4_enum) { return this->_m4; };
	float& operator[] (m5_enum) { return this->_m5; };
	float& operator[] (m6_enum) { return this->_m6; };
	float& operator[] (m7_enum) { return this->_m7; };
	float& operator[] (m8_enum) { return this->_m8; };
	float& operator[] (m9_enum) { return this->_m9; };
	float& operator[] (m10_enum) { return this->_m10; };
	float& operator[] (m11_enum) { return this->_m11; };
	float& operator[] (m12_enum) { return this->_m12; };
	float& operator[] (m13_enum) { return this->_m13; };
	float& operator[] (m14_enum) { return this->_m14; };
	float& operator[] (m15_enum) { return this->_m15; };

	float operator [] (m0_enum)const { return  this->_m0; };
	float operator [] (m1_enum)const { return this->_m1; };
	float operator [] (m2_enum)const { return this->_m2; };
	float operator [] (m3_enum)const { return this->_m3; };
	float operator [] (m4_enum)const { return this->_m4; };
	float operator [] (m5_enum)const { return this->_m5; };
	float operator [] (m6_enum)const { return this->_m6; };
	float operator [] (m7_enum)const { return this->_m7; };
	float operator [] (m8_enum)const { return this->_m8; };
	float operator [] (m9_enum)const { return this->_m9; };
	float operator [] (m10_enum)const { return this->_m10; };
	float operator [] (m11_enum)const { return this->_m11; };
	float operator [] (m12_enum)const { return this->_m12; };
	float operator [] (m13_enum)const { return this->_m13; };
	float operator [] (m14_enum)const { return this->_m14; };
	float operator [] (m15_enum)const { return this->_m15; };

	void set(Matrix::RowType, Vect v);
	void set(Vect v0, Vect v1, Vect v2, Vect v3);
	void set(Quat q);


	Vect get(Matrix::RowType row);

	//accessors <-- spelt right?
	float m0() const { return this->_m0; };
	float m1() const { return this->_m1; };
	float m2() const { return this->_m2; };
	float m3() const { return this->_m3; };
	float m4() const { return this->_m4; };
	float m5() const { return this->_m5; };
	float m6() const { return this->_m6; };
	float m7() const { return this->_m7; };
	float m8() const { return this->_m8; };
	float m9() const { return this->_m9; };
	float m10() const { return this->_m10; };
	float m11() const { return this->_m11; };
	float m12() const { return this->_m12; };
	float m13() const { return this->_m13; };
	float m14() const { return this->_m14; };
	float m15() const { return this->_m15; };

	float & m0() { return this->_m0; };
	float & m1() { return this->_m1; };
	float & m2() { return this->_m2; };
	float & m3() { return this->_m3; };
	float & m4() { return this->_m4; };
	float & m5() { return this->_m5; };
	float & m6() { return this->_m6; };
	float & m7() { return this->_m7; };
	float & m8() { return this->_m8; };
	float & m9() { return this->_m9; };
	float & m10() { return this->_m10; };
	float & m11() { return this->_m11; };
	float & m12() { return this->_m12; };
	float & m13() { return this->_m13; };
	float & m14() { return this->_m14; };
	float & m15() { return this->_m15; };

	//special matrices
	Matrix(Matrix::SpecialType type);
	void set(Matrix::SpecialType);

	//trans
	Matrix(Matrix::TransType, float x = 0, float y = 0, float z = 0);
	Matrix(Matrix::TransType, Vect v);
	void set(Matrix::TransType, float x = 0, float y = 0, float z = 0);
	void set(Matrix::TransType, Vect v);

	//scale
	Matrix(Matrix::ScaleType, float x = 0, float y = 0, float z = 0);
	Matrix(Matrix::ScaleType, Vect v);
	void set(Matrix::ScaleType, float x = 0, float y = 0, float z = 0);
	void set(Matrix::ScaleType, Vect v);

	//rotation
	Matrix(Matrix::RotType, float theta);
	void set(Matrix::RotType, float theta);

	Matrix(Matrix::Rot3AngleType, float x, float y, float z);
	void set(Matrix::Rot3AngleType, float x, float y, float z);

	Matrix(Matrix::RotAxisAngleType, Vect v, float theta);
	void set(Matrix::RotAxisAngleType, Vect v, float theta);

	Matrix(Matrix::RotOrientType type, Vect vUp , Vect vDir);

	void set(Matrix::RotOrientType type, Vect vUp, Vect vDir);



	//booleans
	bool isEqual(Matrix m, float theta = MATH_TOLERANCE);
	bool isIdentity(float theta = MATH_TOLERANCE);

	//matrix simple math
		//unary ops
	Matrix operator+();
	Matrix operator+ (Matrix m);
	void operator +=(Matrix m);

	Matrix operator-();
	Matrix operator -(Matrix m);
	void operator -=(Matrix m);

	Matrix operator *(const float s);
	void operator *=(const float s);
	friend Matrix operator *(float s, const Matrix& v);

	//matrix functions
	Matrix operator *(Matrix m);
	Matrix operator *=(Matrix m);

	float det();
	void T();
	Matrix getT();

	void inv();
	Matrix getInv();
};

#endif

// ---  End of File ---------------

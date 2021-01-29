//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Gam575
//----------------------------------------------------------------------------- 

#include <math.h>

#include "MathEngine.h"

// Do your magic here

//setters
float Vect::operator[](x_enum) const
{
	return this->_vx;
}

float Vect::operator[](y_enum) const
{
	return this->_vy;
}

float Vect::operator[](z_enum) const
{
	return this->_vz;
}

float Vect::operator[](w_enum) const
{
	return this->_vw;
}

float& Vect::operator[](x_enum)
{
	return this->_vx;
}

float& Vect::operator[](y_enum)
{
	return this->_vy;
}

float& Vect::operator[](z_enum)
{
	return this->_vz;
}

float& Vect::operator[](w_enum)
{
	return this->_vw;
}

void Vect::set(float x, float y, float z, float w)
{
	this->_vx = x;
	this->_vy = y;
	this->_vz = z;
	this->_vw = w;
}

void Vect::set(Vect vect) {
	this->_vx = vect._vx;
	this->_vy = vect._vy;
	this->_vz = vect._vz;
	this->_vw = vect._vw;
}

//getters
float& Vect::x() {
	return this->_vx;
}

float& Vect::y() {
	return this->_vy;
}

float& Vect::z() {
	return this->_vz;
}

float& Vect::w() {
	return this->_vw;
}

float Vect::x() const {
	return this->_vx;
}

float Vect::y() const {
	return this->_vy;
}

float Vect::z() const {
	return this->_vz;
}

float Vect::w() const {
	return this->_vw;
}


//Math operators
Vect Vect::operator+(const Vect& v)const {
	return Vect(this->_vx + v._vx, this->_vy + v._vy, this->_vz + v._vz);
}

void Vect::operator+=(const Vect& v) {
	this->_vx += v._vx;
	this->_vy += v._vy;
	this->_vz += v._vz;
	this->_vw = 1;
}

void Vect::MatrixAdd(const Vect& v)
{
	this->_vx += v._vx;
	this->_vy += v._vy;
	this->_vz += v._vz;
	this->_vw += v._vw;
}

Vect Vect::operator-(const Vect v)const {
	return Vect(this->_vx - v._vx, this->_vy - v._vy, this->_vz - v._vz);
}

void Vect::operator-=(const Vect& v) {
	this->_vx -= v._vx;
	this->_vy -= v._vy;
	this->_vz -= v._vz;
	this->_vw = 1;
}

void Vect::MatrixSub(const Vect& v) {
	this->_vx -= v._vx;
	this->_vy -= v._vy;
	this->_vz -= v._vz;
	this->_vw -= v._vw;
}

Vect Vect::operator*(const float s)const
{
	return Vect(this->_vx*s, this->_vy*s, this->_vz*s);
}

void Vect::operator*=(const float s)
{
	this->_vx *= s;
	this->_vy *= s;
	this->_vz *= s;
	this->_vw = 1;
}

void Vect::MatrixScale(const float s) {
	this->_vx *= s;
	this->_vy *= s;
	this->_vz *= s;
	this->_vw *= s;
}


Vect Vect::operator+()
{
	return Vect(this->_vx, this->_vy, this->_vz);
}

Vect Vect::operator-()
{
	return  Vect(-this->_vx, -this->_vy, -this->_vz);
}


Vect operator*(float s, const Vect & v)
{
	return Vect(v._vx*s, v._vy*s, v._vz*s);
}

bool Vect::isEqual(Vect v, const float epsilon)
{
	return (Util::isEqual(this->_vx, v._vx, epsilon) && Util::isEqual(this->_vy, v._vy, epsilon) && Util::isEqual(this->_vz, v._vz, epsilon));
}

bool Vect::isZero(const float epsilon)
{
	return (Util::isZero(this->_vx, epsilon) && Util::isZero(this->_vy, epsilon) && Util::isZero(this->_vz, epsilon) && Util::isOne(this->_vw, epsilon));
}

float Vect::dot(const Vect& v)
{
	return (this->_vx*v._vx + this->_vy*v._vy + this->_vz*v._vz);
}

Vect Vect::cross(const Vect& v)const
{
	return Vect((this->_vy*v._vz - this->_vz*v._vy), (this->_vz*v._vx - this->_vx*v._vz), (this->_vx*v._vy - this->_vy*v._vx));
}

void Vect::norm()
{
	float norm = sqrtf(this->_vx*this->_vx + this->_vy*this->_vy + this->_vz*this->_vz);
	this->_vx /= norm;
	this->_vy /= norm;
	this->_vz /= norm;
}

Vect Vect::getNorm() const
{
	float norm = sqrtf(this->_vx*this->_vx + this->_vy*this->_vy + this->_vz*this->_vz);
	return Vect(this->_vx / norm, this->_vy / norm, this->_vz / norm);
}

float Vect::mag()
{
	return sqrtf(this->_vx*this->_vx + this->_vy*this->_vy + this->_vz*this->_vz);
}

float Vect::magSqr()
{
	return this->_vx*this->_vx + this->_vy*this->_vy + this->_vz*this->_vz;
}

float Vect::getAngle(const Vect& v)
{
	return atan2f(this->cross(v).mag(), this->dot(v));
}

Vect Vect::operator*(const Matrix&  m) const
{
	float v0 = (this->_vx*m[m0] + this->_vy*m[m4] + this->_vz*m[m8] + this->_vw*m[m12]);
	float v1 = (this->_vx*m[m1] + this->_vy*m[m5] + this->_vz*m[m9] + this->_vw*m[m13]);
	float v2 = (this->_vx*m[m2] + this->_vy*m[m6] + this->_vz*m[m10] + this->_vw*m[m14]);
	float v3 = (this->_vx*m[m3] + this->_vy*m[m7] + this->_vz*m[m11] + this->_vw*m[m15]);

	return Vect(v0, v1, v2, v3);
}

Vect Vect::operator*=(const Matrix&  m)
{
	float v0 = (this->_vx*m[m0] + this->_vy*m[m4] + this->_vz*m[m8] + this->_vw*m[m12]);
	float v1 = (this->_vx*m[m1] + this->_vy*m[m5] + this->_vz*m[m9] + this->_vw*m[m13]);
	float v2 = (this->_vx*m[m2] + this->_vy*m[m6] + this->_vz*m[m10] + this->_vw*m[m14]);
	float v3 = (this->_vx*m[m3] + this->_vy*m[m7] + this->_vz*m[m11] + this->_vw*m[m15]);
	this->_vx = v0;
	this->_vy = v1;
	this->_vz = v2;
	this->_vw = v3;
	return *this;
}
// ---  End of File ---------------

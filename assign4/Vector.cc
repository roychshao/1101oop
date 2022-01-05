
extern "C" {
#include <stdio.h>
#include <string.h>
#include <math.h>
}

using namespace std;
#include <iostream>
#include "Vector.h"

// constructors
Vector::Vector() {
	dimension = defaultDimension;
	vector = new double[dimension];
	for (int i = 0; i < dimension; ++i)
		vector[i] = 0;
}

Vector::Vector(int size) {
	dimension = size;
	vector = new double[dimension];
	for (int i = 0; i < dimension; ++i)
		vector[i] = 0;
}

Vector::Vector(int size, const double elem[]) {
	dimension = size;
	vector = new double[dimension];
	for (int i = 0; i < dimension; ++i)
		vector[i] = elem[i];
}


// copy constructor
Vector::Vector(const Vector& v) {
	dimension = v.dimension;
	vector = new double[dimension];
	for (int i = 0; i < dimension; ++i)
		vector[i] = v.vector[i];
}

// assign
Vector&
Vector::operator=(const Vector& v) {
	dimension = v.dimension;
	if (this == &v)
		return *this;
	delete [] vector;
	vector = new double[dimension];
	for (int i = 0; i < dimension; ++i)
		this->vector[i] = v.vector[i];
	return *this;
}

// overload []
double
Vector::operator[](int idx) {
	if (idx >= dimension)
		return 0;
	else
		return vector[idx];
}

// set dimension
void
Vector::setDimension(int size) {
	double *temp = new double[size];
	for (int i = 0; i < size; ++i)
	{
		if (i < dimension)
			temp[i] = vector[i];
		else
			temp[i] = 0;
	}
	dimension = size;
	delete [] vector;
	vector = new double[dimension];
	memcpy(vector, temp, dimension);
	for (int i = 0; i < dimension; ++i)
		vector[i] = temp[i];
	delete [] temp;
}

// overload negator
Vector
Vector::operator -() {
	Vector neg(dimension);
	for(int i = 0; i < dimension; ++i)
		neg.vector[i] = 0 - vector[i];
	return neg;
}

// overload +
Vector
Vector::operator +(Vector vct) {
	if (dimension != vct.dimension)
	{
		cout << "Cannot do plus operation on two different dimension vector !!" << endl;
		return vct;
	}
	Vector plus(dimension);
	for(int i = 0; i < dimension; ++i)
		plus.vector[i] = (this->vector[i] + vct.vector[i]);
	return plus;
}

// overload -
Vector
Vector::operator -(Vector vct) {
	if (dimension != vct.dimension)
	{
		cout << "Cannot do plus operation on two different dimension vector !!" << endl;
		return vct;
	}
	Vector minus(dimension);
	for(int i = 0; i < dimension; ++i)
		minus.vector[i] = (this->vector[i] - vct.vector[i]);
	return minus;
}

// overload vector * double
Vector
Vector::operator *(double scalar) {
	Vector multi(dimension);
	for(int i = 0; i < dimension; ++i)
		multi.vector[i] = (this->vector[i] * scalar);
	return multi;
}

// overload double * vector
Vector
operator *(double scalar, Vector vct) {
	return (vct * scalar);
}

// overload +=
Vector
&Vector::operator +=(Vector vct) {
	// if cannot do plus, print error message
	if (dimension != vct.dimension)
	{
		cout << "Cannot do plus operation on two different dimension vector !!" << endl;
		return *this;
	}
	for(int i = 0; i < dimension; ++i)
		vector[i] += vct.vector[i];
	return *this;
}

// overload -=
Vector
&Vector::operator -=(Vector vct) {
	// if cannot do minus, print error message
	if (dimension != vct.dimension)
	{
		cout << "Cannot do plus operation on two different dimension vector !!" << endl;
		return *this;
	}
	for(int i = 0; i < dimension; ++i)
		vector[i] -= vct.vector[i];
	return *this;
}

// overload *=
Vector
&Vector::operator *=(double scalar) {
	for(int i = 0; i < dimension; ++i)
		vector[i] *= scalar;
	return *this;
}

// overload ==
bool
Vector::operator ==(Vector vct) {
	if (dimension != vct.dimension)
		return false;
	for(int i = 0; i < dimension; ++i)
	{
		if (vector[i] != vct.vector[i])
			return false;
	}
	return true;
}

// overload !=
bool
Vector::operator !=(Vector vct) {
	if (dimension != vct.dimension)
		return true;
	for(int i = 0; i < dimension; ++i)
	{
		if (vector[i] == vct.vector[i])
			return false;
	}
	return true;
}

// return the length of the vector
double
Vector::length() {
	double l = 0;
	for(int i = 0; i < dimension; ++i)
		l += (vector[i] * vector[i]);
	return sqrt(l);
}

// overload <<
ostream&
operator<<(ostream& os, const Vector& vct) {
	os << '(';
	for(int i = 0; i < vct.dimension-1; ++i)
		os << vct.vector[i] << ", ";
	os << vct.vector[vct.dimension-1] << ')';
	return os;
}



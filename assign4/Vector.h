#ifndef _VECTOR_H
#define _VECTOR_H

const int defaultDimension = 2;

class Vector {

public:

	// default constructor ( 2D vector )
	Vector();

	// constructor overloading
	Vector(int size);

	Vector(int size, const double elem[]);
	
	// copy constructor
	Vector(const Vector& v);
	
	// assign
	Vector& operator=(const Vector& v);
	
	// destructor
	inline ~Vector() { delete [] vector; }
	
	// overload []
	double operator[](int idx);
	
	// get dimension
	inline int getDimension() {
		return dimension;
	}

	// set dimension
	void setDimension(int size);
	
	// Arithmetic operators overloading
	Vector operator -();	// negator
	Vector operator +(Vector vct);
	Vector operator -(Vector vct);
	Vector operator *(double scalar);
	Vector &operator +=(Vector vct);
	Vector &operator -=(Vector vct);
	Vector &operator *=(double scalar);

	// Equality Operators
	bool operator ==(Vector vct);
	bool operator !=(Vector vct);

	// Length
	double length();

	// overload <<
	friend ostream &operator<<(ostream &, const Vector &);

private:
	int dimension;
	double *vector;

};

Vector operator *(double scalar, Vector vct);

#endif // _VECTOR_H

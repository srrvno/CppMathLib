//
// Created by srrvno on 8/8/26.
//

// As seen the next three lines are precedeed with #: which are preprocessor directives.

#ifndef CPPMATHLIB_VECTOR2_HPP // Significa: if not defined CPPMATHLIB_VECTOR2_HPP
#define CPPMATHLIB_VECTOR2_HPP // La define
#include <initializer_list> // Para usar std::initializer_list<>

class Vector2 {
public:
	double x = 0.0;
	double y = 0.0;

	Vector2();
	Vector2(const double _x, const double _y);
	Vector2(const std::initializer_list<double> list);

	// Copy constructor
	Vector2(const Vector2& v);

	// Copy by asignation
	Vector2& operator=(const Vector2& v);

	// Move Constructor
	Vector2(Vector2&& vector);

	// Destructor
	~Vector2();

	// Operator []
	double& operator[](size_t index);
	const double& operator[](size_t index) const;

	// print
	void print() const;

	// Scalar arithmetic
	// SUM
	Vector2 operator+(const Vector2& v) const;
	Vector2& operator+=(const Vector2& v);

	Vector2 operator+(double s) const;
	Vector2& operator+=(double s);

	// Substract
	Vector2 operator-(const Vector2& v) const;
	Vector2& operator-=(const Vector2& v);

	Vector2 operator-(double s) const;
	Vector2& operator-=(double s);

	// PRODUCT
	Vector2 operator*(const Vector2& v) const;
	Vector2& operator*=(const Vector2& v);

	Vector2 operator*(double s) const;
	Vector2& operator*=(double s);

	// DIVISION
	Vector2 operator/(const Vector2& v) const;
	Vector2& operator/=(const Vector2& v);

	Vector2 operator/(double s) const;
	Vector2& operator/=(double s);

	// VECTOR PROPERTIES
	double length() const;
	double length2() const;
	double distance(const Vector2& v) const;
	double distance2(const Vector2& v) const;

	// SCALAR PRODUCT
	double dot(const Vector2& v) const;

	// CROSS PRODUCT
	double cross(const Vector2& v) const;

	// ANGLE BETWEEN VECTORS
	double angleTo(const Vector2& other) const;

	// NORMALIZE
	Vector2 normalized() const;
	Vector2& normalize();

	// COMPARISON
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;
	bool isApprox(const Vector2& v, double epsilon=0.000001) const;
};


#endif //CPPMATHLIB_VECTOR2_HPP
//
// Created by srrvno on 8/8/26.
//
#include <iostream>
#include <MathLib/Vector2.hpp>
#include <cmath>

using std::cout;
using std::endl;

// Empty Constructor
Vector2::Vector2(){};

// Constructor by literals
Vector2::Vector2(double _x, double _y)
{
    x = _x; y = _y;
};

// Constructor by initializer list
Vector2::Vector2(std::initializer_list<double> list)
{
    if (list.size() != 2)
    {
        throw std::invalid_argument("Size of initializer list must be 2");
    }
    x = *(list.begin());
    y = *(list.begin() + 1);
}

// Copy constructor
Vector2::Vector2(const Vector2& v)
{
    x = v.x;
    y = v.y;
};

// Copy by asignation
Vector2& Vector2::operator=(const Vector2& v)
{
    // if the same, return itself
    if (this == &v)
    {
        return *this;
    }
    x = v.x;
    y = v.y;
    return *this;
};

// // Move Constructor : NOT NEEDED
// Vector2::Vector2(Vector2&& vector)
// {
//     x = vector.x;
//     y = vector.y;
// };

// Destructor
Vector2::~Vector2(){};

//
double& Vector2::operator[](size_t index){
    if (index > 1) {
        throw std::out_of_range("Index out of range");
    }
	if (index == 0) {
	    return x;
	}
	return y;
}

const double& Vector2::operator[](size_t index) const {
    if (index > 1) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        return x;
    }
    return y;
}

void Vector2::print() const {
    cout << "[" << x << " ," << y << "]"<< endl;
}

// SUM
Vector2 Vector2::operator+(const Vector2& v) const {
    return Vector2{x+v.x,y+v.y};
}
// Ops+asign must return reference to the object due to: chained operations
// and the fact that we want to return the object itself, not a copy:
/* Example:
 *    int a = 1;
 *    int b = 2;
 *    int c = 3;
 *
 *    a += b += c;
 *
 *    // First evaluates (b += c), it has to return something, the correct thing
 *    // is that it returns the same b object now modified, not a copy.
 */
Vector2& Vector2::operator+=(const Vector2& v) {
    x = x+v.x;
    y = y+v.y;
    return *this;
}

Vector2 Vector2::operator+(double s) const {
    return Vector2{x+s,y+s};
};
Vector2& Vector2::operator+=(double s) {
    x = x+s;
    y = y+s;
    return *this;
};

// Substract
Vector2 Vector2::operator-(const Vector2& v) const {
    return Vector2{x-v.x,y-v.y};
}
Vector2& Vector2::operator-=(const Vector2& v) {
    x = x-v.x;
    y = y-v.y;
    return *this;
}

Vector2 Vector2::operator-(double s) const {
    return Vector2{x-s,y-s};
};
Vector2& Vector2::operator-=(double s) {
    x = x-s;
    y = y-s;
    return *this;
};

Vector2 Vector2::operator*(double s) const {
    return Vector2{x*s,y*s};
};
Vector2& Vector2::operator*=(double s) {
    x = x*s;
    y = y*s;
    return *this;
};

// Product
Vector2 Vector2::operator*(const Vector2& v) const {
    return Vector2{x*v.x,y*v.y};
}
Vector2& Vector2::operator*=(const Vector2& v) {
    x = x*v.x;
    y = y*v.y;
    return *this;
}

// Division
Vector2 Vector2::operator/(const Vector2& v) const {
    return Vector2{x/v.x,y/v.y};
}
Vector2& Vector2::operator/=(const Vector2& v) {
    x = x/v.x;
    y = y/v.y;
    return *this;
}

Vector2 Vector2::operator/(double s) const {
    return Vector2{x/s,y/s};
};
Vector2& Vector2::operator/=(double s) {
    x = x/s;
    y = y/s;
    return *this;
};

// VECTOR PROPERTIES
double Vector2::length() const {
    return sqrt(x*x + y*y);
}

double Vector2::length2() const {
    return x*x + y*y;
}

double Vector2::distance(const Vector2& v) const {
    return sqrt((v.x-x)*(v.x-x) + (v.y-y)*(v.y-y));
}
double Vector2::distance2(const Vector2& v) const {
    return (v.x-x)*(v.x-x) + (v.y-y)*(v.y-y);
}

double Vector2::dot(const Vector2& v) const {
    return x*v.x + y*v.y;
}

double Vector2::cross(const Vector2& v) const {
    return x*v.y - y*v.x;
}

/* ANGLE BETWEEN TWO VECTORS:
 *
 * The dot product can also be expressed geometrically as:
 *
 *      A · B = ||A|| * ||B|| * cos(theta)
 *
 * where:
 *      A · B       -> dot product
 *      ||A||,||B|| -> lengths (magnitudes) of the vectors
 *      theta       -> angle between them
 *
 * To obtain the angle, first isolate cos(theta):
 *
 *                        A · B
 *      cos(theta) = -----------------
 *                     ||A|| * ||B||
 *
 * Then apply the inverse cosine (arccos) to both sides:
 *
 *      theta = arccos((A · B) / (||A|| * ||B||))
 *
 * arccos() is the inverse function of cos(): if cos(theta) = x,
 * then theta = arccos(x).
 *
 * NOTE: neither vector can be the zero vector, since its length is 0
 * and this would cause a division by zero.
 */

double Vector2::angleTo(const Vector2& other) const {
    double l = length();
    double lb = other.length();

    if (lb == 0.0 || l == 0.0) {
        throw std::runtime_error("Cannot use vector [0,0]");
    }
    return std::acos(dot(other)/(l*lb));
}

/* VECTOR PROJECTION:
 *
 * Projects vector A onto the direction of vector B.
 * Geometrically, it represents the part of A that points
 * in the same (or opposite) direction as B.
 *
 * Scalar projection (length along B):
 *
 *                  A · B
 *      comp_B(A) = -------
 *                   ||B||
 *
 * To turn that scalar into a vector, we multiply it by the
 * unit vector of B:
 *
 *                  B
 *      B_unit = ---------
 *                ||B||
 *
 * Therefore:
 *
 *                      A · B
 *      proj_B(A) = ------------ * B
 *                     ||B||^2
 *
 * The resulting vector is always parallel to B.
 *
 * NOTE: B cannot be the zero vector because ||B|| = 0 would
 * cause a division by zero.
 */

Vector2 Vector2::project(const Vector2& other) const {
    double l2b = other.length2();
    if (l2b == 0.0) {
        throw std::runtime_error("Cannot use vector [0,0]");
    }
    return other * (dot(other) / l2b);
}



Vector2 Vector2::normalized() const {
    if (x == 0.0 && y == 0.0) {
        throw std::runtime_error("Cannot normalize vector [0,0]");
    }
    double mag = length();
    return Vector2{x/mag,y/mag};
}

Vector2& Vector2::normalize() {
    if (x == 0.0 && y == 0.0) {
        throw std::runtime_error("Cannot normalize vector [0,0]");
    }
    double mag = length();
    x /= mag;
    y /= mag;
    return *this;
}

bool Vector2::operator==(const Vector2& v) const {
    return x == v.x && y == v.y;
}

bool Vector2::operator!=(const Vector2& v) const {
    return !(*this==(v));
}

bool Vector2::isApprox(const Vector2& v, double epsilon) const {
    return std::abs(x - v.x)< epsilon && std::abs(y - v.y) < epsilon;
}











#include <iostream>
#include <MathLib/Vector3.hpp>
#include <cmath>

using std::cout;
using std::endl;

// Empty
Vector3::Vector3(){}

// Values
Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}


// Copy
Vector3::Vector3(const Vector3& vector) {
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

// Copy assignment
Vector3& Vector3::operator=(const Vector3& other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}

// Init list
Vector3::Vector3(std::initializer_list<double> list) {
    if (list.size() == 0) return;
    if (list.size() != 3) {
        throw std::invalid_argument("Invalid vector size");
    }
    this->x = *(list.begin());
    this->y = *(list.begin()+1);
    this->z = *(list.begin()+2);
}

// Destrcutor
Vector3::~Vector3(){}

// Print
void Vector3::print() const {
    cout << "[" << this->x << "," << this->y << "," << this->z << "]" << endl;
}

// Operator []
const double& Vector3::operator[](size_t index) const {
    if (index > 2) {
        throw std::out_of_range("Invalid index");
    }
    return index == 0 ? this->x : index == 1 ? this->y : this->z;
}

double& Vector3::operator[](size_t index) {
    if (index > 2) {
        throw std::out_of_range("Invalid index");
    }
    return index == 0 ? this->x : index == 1 ? this->y : this->z;
}

// ARITHMETIC OPS

// SUM
Vector3 Vector3::operator+(double scalar) const {
    return Vector3{this->x + scalar, this->y + scalar, this->z + scalar};
}
Vector3& Vector3::operator+=(double scalar) {
    this->x += scalar;
    this->y += scalar;
    this->z += scalar;
    return *this;
}
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3{this->x + other.x, this->y + other.y, this->z + other.z};
}
Vector3& Vector3::operator+=(const Vector3& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

// SUBTRACT
Vector3 Vector3::operator-(double scalar) const {
    return Vector3{this->x - scalar, this->y - scalar, this->z - scalar};
}
Vector3& Vector3::operator-=(double scalar) {
    this->x -= scalar;
    this->y -= scalar;
    this->z -= scalar;
    return *this;
}
Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3{this->x - other.x, this->y - other.y, this->z - other.z};
}
Vector3& Vector3::operator-=(const Vector3& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

// PRODUCT
Vector3 Vector3::operator*(double scalar) const {
    return Vector3{this->x * scalar, this->y * scalar, this->z * scalar};
}
Vector3& Vector3::operator*=(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}
Vector3 Vector3::operator*(const Vector3& other) const {
    return Vector3{this->x * other.x, this->y * other.y, this->z * other.z};
}
Vector3& Vector3::operator*=(const Vector3& other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return *this;
}

// DIV
Vector3 Vector3::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Cannot divide by 0");
    }
    return Vector3{this->x / scalar, this->y / scalar, this->z / scalar};
}
Vector3& Vector3::operator/=(double scalar) {
    if (scalar == 0.0) {
        throw std::invalid_argument("Cannot divide by 0");
    }
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
}
Vector3 Vector3::operator/(const Vector3& other) const {
    if (other.x == 0.0 || other.y == 0.0 || other.z == 0.0) {
        throw std::invalid_argument("Cannot divide by 0");
    }
    return Vector3{this->x / other.x, this->y / other.y, this->z / other.z};
}
Vector3& Vector3::operator/=(const Vector3& other) {
    if (other.x == 0.0 || other.y == 0.0 || other.z == 0.0) {
        throw std::invalid_argument("Cannot divide by 0");
    }
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
    return *this;
}

// VECTOR PROPERTIES
double Vector3::length() const {
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}
double Vector3::length2() const {
    return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

double Vector3::distance(const Vector3& other) const {
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    double dz = this->z - other.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
double Vector3::distance2(const Vector3& other) const {
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    double dz = this->z - other.z;
    return dx * dx + dy * dy + dz * dz;
}

// VECTOR OPS
double Vector3::dot(const Vector3& other) const {
    return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

    /*
     * CROSS PRODUCT:
     *
     * A x B = (
     *     Ay*Bz - Az*By,
     *     Az*Bx - Ax*Bz,
     *     Ax*By - Ay*Bx
     * )
     *
     * Returns a new Vector3 perpendicular to both A and B.
     * Its direction follows the right-hand rule, and its magnitude
     * represents the area of the parallelogram formed by A and B.
     */
Vector3 Vector3::cross(const Vector3& other) const {
    double cx = this->y*other.z - this->z*other.y;
    double cy = this->z*other.x - this->x*other.z;
    double cz = this->x*other.y - this->y*other.x;
    return Vector3{cx, cy, cz};

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

double Vector3::angleTo(const Vector3& other) const {
    double l = length();
    double lb = other.length();

    if (lb == 0.0 || l == 0.0) {
        throw std::runtime_error("Cannot use vector [0,0,0]");
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

Vector3 Vector3::project(const Vector3& other) const {
    double l2b = other.length2();
    if (l2b == 0.0) {
        throw std::runtime_error("Cannot use vector [0,0,0]");
    }
    return other * (dot(other) / l2b);
}

Vector3 Vector3::normalized() const {
    if (x == 0.0 && y == 0.0 && z == 0.0) {
        throw std::runtime_error("Cannot normalize vector [0,0,0]");
    }
    const double length = this->length();
    return Vector3{this->x/length, this->y/length, this->z/length};
}
Vector3& Vector3::normalize() {
    if (x == 0.0 && y == 0.0 && z == 0.0) {
        throw std::runtime_error("Cannot normalize vector [0,0,0]");
    }
    const double length = this->length();
    this->x /= length;
    this->y /= length;
    this->z /= length;
    return *this;
}

// COMPARISON
bool Vector3::operator==(const Vector3& other) const{
    return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
}
bool Vector3::operator!=(const Vector3& other) const {
    return !(*this == other);
}
bool Vector3::isApprox(const Vector3& other, double epsilon) const {
    return (std::abs(this->x - other.x) < epsilon) && (std::abs(this->y - other.y) < epsilon) && (std::abs(this->z - other.z) < epsilon);
}

Vector3 operator+(const double scalar, const Vector3& v) {
    return v+scalar;
}

Vector3 operator-(const double scalar, const Vector3& v) {
    return (v-scalar)*-1;
}

Vector3 operator*(const double scalar, const Vector3& v) {
    return v*scalar;
}

Vector3 operator/(const double scalar, const Vector3& v) {
    if (v.x == 0.0 || v.y == 0.0 || v.z == 0.0) {
        throw std::runtime_error("Cannot divide by zero");
    }
    return Vector3{scalar/v.x,scalar/v.y};
}





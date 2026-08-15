#ifndef CPPMATHLIB_VECTOR3_HPP // Significa: if not defined CPPMATHLIB_VECTOR2_HPP
#define CPPMATHLIB_VECTOR3_HPP // La define
#include <initializer_list> // Para usar std::initializer_list<>

class Vector3 {
    public:
    double x = 0, y = 0, z = 0;

    // Empty
    Vector3();
    // Constructor
    Vector3(double x, double y, double z);
    // Copy
    Vector3(const Vector3& other);
    // Copy assignment
    Vector3& operator= (const Vector3& other);
    // Initializer list cosntructor
    Vector3(std::initializer_list<double> list);
    // Destructor
    ~Vector3();

    // print
    void print() const;

    // Operator []
    //  * Const for just reading
    const double& operator[](size_t index) const;
    //  * Public for assignment
    double& operator[](size_t index);

    // ARITHMETIC OPS

    // SUM
    // * He visto que es logico que las ops a secas devuelvan por valor
    //   ya que devuelven un objeto nuevo, que dentro de la fx es temporal
    //   por lo que no vamos a devolver una ref a un objeto temporal, y
    //   como el objeto propio no se modifica no devolvemos su referencia.
    //   Por ello en caso de op devolvemos valor, pero en op+assign devolvemos ref.
    Vector3 operator+(double scalar) const; // Scalar sum
    Vector3& operator+=(double scalar); // Scalar sum + assign
    Vector3 operator+(const Vector3& other) const; // Vector sum
    Vector3& operator+=(const Vector3& other); // Vector sum and assign

    // SUBTRACT
    Vector3 operator-(double scalar) const; // Scalar subtract
    Vector3& operator-=(double scalar); // Scalar subtract + assign
    Vector3 operator-(const Vector3& other) const; // Vector subtract
    Vector3& operator-=(const Vector3& other); // Vector subtract and assign

    // PRODUCT
    Vector3 operator*(double scalar) const; // Scalar product
    Vector3& operator*=(double scalar); // Scalar product + assign
    Vector3 operator*(const Vector3& other) const; // Vector product
    Vector3& operator*=(const Vector3& other); // Vector product and assign

    // DIVISION
    Vector3 operator/(double scalar) const; // Scalar div
    Vector3& operator/=(double scalar); // Scalar div + assign
    Vector3 operator/(const Vector3& other) const; // Vector div
    Vector3& operator/=(const Vector3& other); // Vector div and assign

    // VECTOR PROPERTIES
    double length() const;
    double length2() const;

    double distance(const Vector3& other) const;
    double distance2(const Vector3& other) const;

    // VECTOR OPS
    double dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    // ANGLE BETWEEN VECTORS
    double angleTo(const Vector3& other) const;
    // PROJECTION
    Vector3 project(const Vector3& other) const;
    Vector3 normalized() const;
    Vector3& normalize();

    // COMPARISON
    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;
    bool isApprox(const Vector3& other, double epsilon = 0.0000001) const;
};

Vector3 operator+(double scalar, const Vector3& v);

Vector3 operator-(double scalar, const Vector3& v);

Vector3 operator*(double scalar, const Vector3& v);

Vector3 operator/(double scalar, const Vector3& v);


#endif //CPPMATHLIB_VECTOR3_HPP
#ifndef CPPMATHLIB_MATRIX2_CPP
#define CPPMATHLIB_MATRIX2_CPP

#include <initializer_list>
#include <MathLib/Vector2.hpp>

class Matrix2 {
    public:

    double data[2][2] = {{0, 0}, {0, 0}};

    // Empty Constructor
    Matrix2();

    // Double Constructor
    Matrix2(double m00, double m01, double m10, double m11);

    // Initializer List Constructor
    Matrix2(std::initializer_list<std::initializer_list<double>>);

    // Copy constructor
    Matrix2(const Matrix2& other);

    // Copy assignment
    Matrix2& operator=(const Matrix2& other);

    // Destructor
    ~Matrix2();

    // Print
    void print() const;

    // Operator []
    double (&operator[](size_t i))[2];
    const double (&operator[](size_t i) const)[2];

    // Arithmetic Ops
    // SUM
    Matrix2 operator+(double scalar) const;
    Matrix2& operator+=(double scalar);
    Matrix2 operator+(const Matrix2& other) const;
    Matrix2& operator+=(const Matrix2& other);

    //SUBTRACT
    Matrix2 operator-(double scalar) const;
    Matrix2& operator-=(double scalar);
    Matrix2 operator-(const Matrix2& other) const;
    Matrix2& operator-=(const Matrix2& other);

    // PRODUCT
    Matrix2 operator*(double scalar) const;
    Matrix2& operator*=(double scalar);
    Matrix2 operator*(const Matrix2& other) const;
    Matrix2& operator*=(const Matrix2& other);

    Vector2 operator*(const Vector2& vector) const;

    // DIVISION
    Matrix2 operator/(double scalar) const;
    Matrix2& operator/=(double scalar);
    Matrix2 operator/(const Matrix2& other) const;
    Matrix2& operator/=(const Matrix2& other);

    // MATRIX OPS
    double det() const;
    Matrix2 T() const;
    Matrix2& transpose();


};

#endif // CPPMATHLIB_MATRIX2_CPP

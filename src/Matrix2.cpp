#include <MathLib/Matrix2.hpp>
#include <MathLib/Vector2.hpp>
#include <iostream>
#include <bits/syscall.h>

using std::cout;
using std::endl;

Matrix2::Matrix2(){}

Matrix2::Matrix2(double m00, double m01, double m10, double m11) {
    this->data[0][0] = m00;
    this->data[0][1] = m01;
    this->data[1][0] = m10;
    this->data[1][1] = m11;
}

Matrix2::Matrix2(std::initializer_list<std::initializer_list<double>> list) {
    if (list.size() == 0) return;

    if (list.size() != 2 ||
        list.begin()[0].size() != 2 ||
        list.begin()[1].size() != 2) {
        throw std::invalid_argument("Matrix2 must be of size 2x2");
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] = list.begin()[i].begin()[j];
        }
    }
}

// Copy constructor
Matrix2::Matrix2(const Matrix2& other) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }
}

// Copy assignment
Matrix2& Matrix2::operator=(const Matrix2& other) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

// Destructor
Matrix2::~Matrix2() {}

// Print
void Matrix2::print() const {
    cout << "⎡ " << data[0][0] << " " << data[0][1] << " ⎤" << endl;
    cout << "⎣ " << data[1][0] << " " << data[1][1] << " ⎦" << endl;
}



// OPERATOR []



double (&Matrix2::operator[](size_t i))[2] {
    if (i > 1) {
        throw std::out_of_range("Matrix2 index out of range");
    }

    return this->data[i];
}

const double (&Matrix2::operator[](size_t i) const)[2] {
    if (i > 1) {
        throw std::out_of_range("Matrix2 index out of range");
    }

    return this->data[i];
}




// #### ARITHMETIC OPERATIONS

// SUM
Matrix2 Matrix2::operator+(double scalar) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] = this->data[i][j] + scalar;
        }
    }
    return result;
}

Matrix2& Matrix2::operator+=(double scalar) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] += scalar;
        }
    }
    return *this;
}

Matrix2 Matrix2::operator+(const Matrix2& other) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] =
                this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix2& Matrix2::operator+=(const Matrix2& other) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] += other.data[i][j];
        }
    }
    return *this;
}



// SUBTRACT
Matrix2 Matrix2::operator-(double scalar) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] = this->data[i][j] - scalar;
        }
    }
    return result;
}

Matrix2& Matrix2::operator-=(double scalar) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] -= scalar;
        }
    }
    return *this;
}

Matrix2 Matrix2::operator-(const Matrix2& other) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] =
                this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix2& Matrix2::operator-=(const Matrix2& other) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}



// PRODUCT WITH SCALAR
Matrix2 Matrix2::operator*(double scalar) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] =
                this->data[i][j] * scalar;
        }
    }

    return result;
}

Matrix2& Matrix2::operator*=(double scalar) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] *= scalar;
        }
    }
    return *this;
}



// MATRIX PRODUCT
/*
C[i][j] = sum(A[i][k] * B[k][j])

Each element of the result is the dot product between
one row of A and one column of B.
*/
Matrix2 Matrix2::operator*(const Matrix2& other) const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < 2; k++) {
                result.data[i][j] +=
                    this->data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix2& Matrix2::operator*=(const Matrix2& other) {
    // We need a temporary matrix because the original values of
    // *this are required until the whole product has been calculated.
    Matrix2 result = (*this) * other;
    *this = result;
    return *this;
}



// MATRIX * VECTOR
/*
Vectors in MathLib are treated as column vectors:

     |a b| |x|   [ax + by]
     |c d| |y| = [cx + dy]
*/
Vector2 Matrix2::operator*(const Vector2& vector) const {
    Vector2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i] += this->data[i][j] * vector[j];
        }
    }
    return result;
}



// DIVISION BY SCALAR
Matrix2 Matrix2::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::runtime_error("Cannot divide by zero");
    }
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] =
                this->data[i][j] / scalar;
        }
    }
    return result;
}

Matrix2& Matrix2::operator/=(double scalar) {
    if (scalar == 0.0) {
        throw std::runtime_error("Cannot divide by zero");
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] /= scalar;
        }
    }
    return *this;
}



// MATRIX / MATRIX
/*
NOTE: This is NOT standard matrix division.
In MathLib this operation is defined as component-wise division:

     C[i][j] = A[i][j] / B[i][j]
*/
Matrix2 Matrix2::operator/(const Matrix2& other) const {
    Matrix2 result;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            if (other.data[i][j] == 0.0) {
                throw std::runtime_error("Cannot divide by zero");
            }

            result.data[i][j] =
                this->data[i][j] / other.data[i][j];
        }
    }

    return result;
}

Matrix2& Matrix2::operator/=(const Matrix2& other) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            if (other.data[i][j] == 0.0) {
                throw std::runtime_error("Cannot divide by zero");
            }

            this->data[i][j] /= other.data[i][j];
        }
    }

    return *this;
}

double Matrix2::det() const {
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
}

Matrix2 Matrix2::T() const {
    Matrix2 result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.data[i][j] = this->data[j][i];
        }
    }
    return result;
}

Matrix2& Matrix2::transpose() {
    Matrix2 copy = *this;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->data[i][j] = copy[j][i];
        }
    }
    return *this;
}

#include <iostream>
#include <MathLib/Matrix2.hpp>
#include <MathLib/Vector2.hpp>

using std::cout;
using std::endl;

void spc() {
    cout<<endl;
}

int main() {
    Matrix2 m0;
    Matrix2 m1{{1,2},{3,4}};

    m0.print();
    spc();
    m1.print();
    spc();

    Matrix2 m2 = m0 + m1;
    m2.print();
    spc();

    cout << "m2 =" << endl;
    m2 += m2;
    m2.print();
    spc();

    cout << "m2 -= m1:" << endl;
    m2 -= m1;
    m2.print();
    spc();

    cout << "m2 *= m2:" << endl;
    m2 *= m2;
    m2.print();
    spc();

    cout << "m2 /= m2:" << endl;
    m2 /= m2;
    m2.print();
    spc();

    cout << "m2.normalized():" << endl;

    return 0;
}
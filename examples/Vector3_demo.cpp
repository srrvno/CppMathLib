#include <iostream>
#include <MathLib/Vector3.hpp>

using std::cout;
using std::endl;

void spc(int n=1) {
    for (int i = 0; i < n; i++) {
        cout << endl;
    }
}

int main () {
    Vector3 v0;
    Vector3 v1(1,2,3);
    Vector3 v2{3,4,5};
    Vector3 v3 = Vector3{6,7,8};

    cout << "v0 = ";
    v0.print();
    spc();
    cout << "v1 = ";
    v1.print();
    spc();

    cout << "v1.x = " << v1.x << endl;
    cout << "v1[0] = " << v1[0]<< endl;

    v1.y = 8;
    v1[2] = 2;
    cout << "Now:\n v1.y = 8\n v1[2] = 2\n → v1 = ";
    v1.print();
    spc();

    cout << "v0 + v1 = ";
    (v0 + v1).print();
    spc();

    cout << "v0 = ";
    v0.print();
    spc();

    cout << "v0 += v1 " << endl;
    v0+=v1;
    cout << "v0 = ";
    v0.print();
    spc();

    cout << "v3 = ";
    v3.print();
    cout << "v3.length() = " << v3.length() << endl;
    spc();

    cout << "v3.distance(v1) = " << v3.distance(v1) << endl;
    spc();

    cout << "v0.dot(v2) = " << v0.dot(v2) << endl;
    spc();

    cout << "v0.cross(v2) = ";
    (v0.cross(v2)).print();
    spc();


    cout << "v0 = ";
    v0.print();
    cout << "v0.normalized() = ";
    v0.normalized().print();
    spc();

    cout << "v0 = ";
    v0.print();
    cout << "v1 = ";
    v1.print();
    cout << "v0 == v1 = " << (v0 == v1) << endl;
    cout << "v0 != v1 = " << (v0 != v1) << endl;

}
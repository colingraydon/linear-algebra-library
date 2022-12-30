#include "Matrix.h"
#include <iostream>

using namespace std;
using namespace matrix;

int main()
{
    //Matrix t;
    Matrix u(1, 2);
    Matrix v(1, 2);
    //Matrix w(4, 4);
    u.populateMatrix();
    v.populateMatrix();
    //w.randomValueMatrix();
    u.printMatrix();
    v.printMatrix();
    // w.printMatrix();
    // u = v;
    // u.printMatrix();
    //Matrix z(u+v);
    // Matrix z = u + v;
    // z.printMatrix();
    // Matrix z = u - v;
    // z.printMatrix();
    // cout << "Before Matrix z = u + v" << endl;
    // z = u + v;
    // cout << "After Matrix z = u + v" << endl;
    // z.printMatrix();
    // u += v;
    // u.printMatrix();
    // u -= v;
    // u.printMatrix();
    // u = 2 * v;
    // u.printMatrix();
    Matrix z;
    z = u * v;
    z.printMatrix();


}
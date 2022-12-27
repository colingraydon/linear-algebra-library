#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace matrix;

int main()
{
    Matrix t;
    Matrix u(2, 2);
    Matrix v(2, 2);
    Matrix w(3, 3);
    u.populateMatrix();
    v.randomValueMatrix();
    w.randomValueMatrix();
    u.printMatrix();
    v.printMatrix();
    w.printMatrix();
    // v += u;
    // //w += v;
    // w -= w;
    //v + u;
    // //w + u;
    v.printMatrix();
    // u.printMatrix();
    // w.printMatrix();
    u.printMatrix();
    Matrix z = u - v;
    z.printMatrix();
    // z = u - v;
    // z.printMatrix();
}
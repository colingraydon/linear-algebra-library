#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;

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
    v += u;
    w += v;
    w -= w;
    v.printMatrix();
    u.printMatrix();
    w.printMatrix();
}
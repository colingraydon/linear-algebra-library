#include "Matrix.h"
#include <iostream>

using namespace std;
using namespace matrix;

int main()
{
    //Matrix t;

    double array[2][2] = { {2, 2}, {2, 2}};
    Matrix u(2, 2);

    cout << "u = below---------------"<< endl;    
    u.printMatrix();



}
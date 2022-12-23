#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

namespace matrix
{
    class Matrix
    {
    private:
    int m; //holds row size
    int n; //holds column size
    double **mat;
    void createMatrix();

    public:
    Matrix(); //default constructor
    Matrix(int row, int column); //parameterized constructor
    ~Matrix(); //deconstructor
    void printMatrix() const; //prints the matrix
    void populateMatrix(); //fill matrix with values
    void randomValueMatrix(); //populate matrix with random values between 1 and 100, mostly for quick testing

    //overloaded operators
    friend Matrix operator + (const Matrix& leftOp, const Matrix& rightOp); //overloaded addition operator
    friend Matrix operator - (const Matrix& leftOp, const Matrix& rightOp); //overloaded addition operator
    Matrix& operator += (const Matrix& rightOp); //overloaded shorthand addition operator
    Matrix& operator -= (const Matrix& rightOp); //overloaded shorthand addition operator
    } ;

#endif
}




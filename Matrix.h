#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;


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
    Matrix& Matrix::operator +=(const Matrix& rightOp); //overloaded shorthand addition operator
    Matrix& Matrix::operator -=(const Matrix& rightOp); //overloaded shorthand addition operator
    //friend Matrix operator + (const Matrix& leftOp, const Fraction& rightOp); //overloaded addition operator
   


} ;


#endif


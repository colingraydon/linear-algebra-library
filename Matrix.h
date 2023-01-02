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
    double **mat; //pointer to a matrix
    void createMatrix(); //helper function to initialize matrix size in m x n format

    public:
    //Matrix(const Matrix& copyMe); //copy constructor that makes a deep copy 
    Matrix(); //default constructor 

    Matrix(double**);

    Matrix(int row, int column); //parameterized constructor, 2 arguments
    ~Matrix(); //deconstructor
    Matrix(const Matrix& copyMe); //copy constructor
    Matrix operator = (const Matrix& right); //overloaded assignment (=) operator
    void printMatrix() const; //prints the matrix
    void populateMatrix(); //fill matrix with values
    void randomValueMatrix(); //populate matrix with random values between 1 and 100, mostly for quick testing

    //overloaded operators
    friend Matrix operator + (const Matrix& leftOp, const Matrix& rightOp); //overloaded addition operator
    friend Matrix operator - (const Matrix& leftOp, const Matrix& rightOp); //overloaded addition operator
    friend Matrix operator * (double scalar, const Matrix& rightOp); //overloaded multiplication operator for scalar multiplication
    friend Matrix operator * (const Matrix& rightOp, const Matrix& leftOp); //overloaded multiplication operator for matrix multiplication
    Matrix operator += (const Matrix& rightOp); //overloaded shorthand addition operator
    Matrix operator -= (const Matrix& rightOp); //overloaded shorthand addition operator
    
    } ;
}
#endif




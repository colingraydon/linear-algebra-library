#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

namespace matrix
{
    //private helper function to create matrix in m x n format
    void Matrix::createMatrix()
    {
        mat = new double*[m];
        for (int i = 0; i < m; ++i)
        {
            mat[i] = new double[n];
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = 0;
            }
        }
    }

    //default constructor
    Matrix::Matrix()
    {
        cout << "Default Constructor!" << endl;
        m = 0;
        n = 0;
        createMatrix();
    }


    Matrix::Matrix(double** array, int row, int column) {

        m = row;
        n = column;

        
        mat = new double*[row];
        for (int i = 0; i < row; ++i) {
            mat[i] = new double[column];
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                mat[i][j] = array[i][j];
            }
        }
    }
    //parameterized constructor
    Matrix::Matrix(int row, int column)
    {
        cout << "Parameterized Constructor!" << endl;
        m = row;
        n = column;
        createMatrix();
    }

    Matrix::Matrix(const Matrix& copyMe) 
    {
        m = copyMe.m;
        n = copyMe.n;
        createMatrix();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = copyMe.mat[i][j];
            }
        }
    }

    //overloaded assignment (=) operator
    Matrix Matrix::operator = (const Matrix& right)
    {
        cout << "Copy Constructor!" << endl;
        if (this != &right)
        {
            if (m != right.m || n != right.n)
            {
                for (int i = 0; i < m; ++i)
                {
                    delete[] mat[i];
                }
                delete[] mat;
            }

        m = right.m;
        n = right.n;
        createMatrix();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = right.mat[i][j];
            }
        }
    
        }
        return *this;
    }

    //deconstructor
    Matrix::~Matrix()
    {
        cout << "Deconstructor!" << endl;
        for (int i = 0; i < m; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    //print function
    void Matrix::printMatrix() const
    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << fixed << setprecision(2);
                cout << left << setw(10) << mat[row][col];
            }

            cout << endl;
        }

        cout << endl;

    }

    //populate matrix with values
    void Matrix::populateMatrix()
    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << "Please enter a value for row " << row + 1 << " column " << col + 1 << ": ";
                cin >> mat[row][col];
            }
        }
    }

    //populate matrix with values between 1 and 100
    void Matrix::randomValueMatrix()
    {
        unsigned seed = time(0); //for random numbers
        srand(seed); //for random numbers
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                mat[row][col] = 1 + rand() % 100;
            }
        }
    }


    //overloaded operators

    //overloaded (+) operator
    Matrix operator + (const Matrix& leftOp, const Matrix& rightOp)
    {
        //throw error and input validation loop to go here later
        Matrix sum(rightOp.m, rightOp.n);
        if (leftOp.m != rightOp.m || leftOp.n != rightOp.n)
        {
            cout << "Error! Matrix addition not defined for two matrices not of the same size" << endl;
        }
        else
        {
            for (int row = 0; row < rightOp.m; ++row)
            {
                for (int col = 0; col < rightOp.n; ++col)
                {
                    sum.mat[row][col] = leftOp.mat[row][col] + rightOp.mat[row][col];
                }
            }
        }
        return sum;
    }

    //overloaded subtraction operator
    Matrix operator - (const Matrix& leftOp, const Matrix& rightOp)
    {
        //throw error and input validation loop to go here later
        Matrix difference(rightOp.m, rightOp.n);
        if (leftOp.m != rightOp.m || leftOp.n != rightOp.n)
        {
            cout << "Error! Matrix addition not defined for two matrices not of the same size" << endl;
        }
        else
        {
            for (int row = 0; row < rightOp.m; ++row)
            {
                for (int col = 0; col < rightOp.n; ++col)
                {
                    difference.mat[row][col] = leftOp.mat[row][col] - rightOp.mat[row][col];
                }
            }
        }
        return difference;
    }

    //overloaded shorthand addition operator
    Matrix Matrix::operator +=(const Matrix& rightOp)
    {
        *this = *this + rightOp;
        return *this;
        
        //throw error and input validation loop to go here later
        // if (this->m != rightOp.m || this->n != rightOp.n)
        // {
        //     cout << "Error! Matrix addition not defined for two matrices not of the same size" << endl;
        // }
        // else
        // {
        //     for (int row = 0; row < rightOp.m; row++)
        //     {
        //         for (int col = 0; col < rightOp.n; col++)
        //         {
        //             this->mat[row][col] += rightOp.mat[row][col];
        //         }
        //     }
        // }
        // return *this;
    }

    //overloaded shorthand addition operator
    Matrix Matrix::operator -=(const Matrix& rightOp)
    {
        *this = *this - rightOp;
        return *this;
        
        // const string notSameSize = "ERROR: Matrix subtraction is not defined for for two matrices that are not the same size. \n";
        // if (this->m != rightOp.m || this->n != rightOp.n)
        // {
        //     cout << notSameSize << endl;
        //     exit;
        // }
        // else
        // {
        //     for (int row = 0; row < rightOp.m; row++)
        //     {
        //         for (int col = 0; col < rightOp.n; col++)
        //         {
        //             mat[row][col] -= rightOp.mat[row][col];
        //         }
        //     }
        // }
        // return *this;
    }

    //overloaded multiplication operator for scalar multiplication
    Matrix operator * (double scalar, const Matrix& rightOp)
    {
        Matrix scalarMulti(rightOp.m, rightOp.n);
        for (int i = 0; i < rightOp.m; ++i)
        {
            for (int j = 0; j < rightOp.n; ++j)
            {
                scalarMulti.mat[i][j] = scalar * rightOp.mat[i][j];
            }
        }
        return scalarMulti;
    }

    //overloaded multiplication operator for matrix multiplication
    Matrix operator * (const Matrix& rightOp, const Matrix& leftOp)
    {
        //write throw/catch error and input validation later
        Matrix multi(rightOp.m, leftOp.n);
        if (rightOp.n != leftOp.m)
        {
            cout << "Matrix multiplication isn't defined for these two matrices" << endl;
        }
        else
        {
            for (int row = 0; row < rightOp.m; ++row)
            {
                for (int col = 0; col < leftOp.n; ++col)
                {
                    for (int k = 0; k < rightOp.n; ++k)
                    {
                        multi.mat[row][col] = multi.mat[row][col] + (rightOp.mat[row][k] * leftOp.mat[k][col]);
                        //iterates nth times, where n is either the number of columns of the right matrix or the number of rows of the left matrix
                    }
                }
            }
        }
        return multi;
    }

}
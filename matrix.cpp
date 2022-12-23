#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

namespace matrix
{
    //private helper function to create matrix
    void Matrix::createMatrix()
    {
        mat = new double*[m];
        for (int i = 0; i < m; ++i)
        {
            mat[i] = new double[n];
        }
    }
    
    //default constructor
    Matrix::Matrix()
    {
        cout << "Default constructor!" << endl;
        m = 0;
        n = 0;
        createMatrix();
    }
    //parameterized constructor
    Matrix::Matrix(int row, int column) 
    {
        cout << "Parameterized constructor!" << endl;
        m = row;
        n = column;
        createMatrix();
    }
    //deconstructor
    Matrix::~Matrix()
    {
        cout << "Destructor!" << endl;
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
    
    //overloaded addition operator
    Matrix operator + (const Matrix& leftOp, const Matrix& rightOp)
    {
        const string notSameSize = "ERROR: Matrix subtraction is not defined for for two matrices that are not the same size. \n";
        Matrix sum(rightOp.m, rightOp.n);
        if (leftOp.m != rightOp.m || leftOp.n != rightOp.n)
        {
            cout << notSameSize << endl;
            exit;
        }
        else
        {
            for (int row = 0; row < rightOp.m; row++)
            {
                for (int col = 0; col < rightOp.n; col++)
                {
                    sum.mat[row][col] = leftOp.mat[row][col] + rightOp.mat[row][col];
                    cout << sum.mat[row][col] << endl;
                }
            }
        }
        return sum;
    }

    //overloaded subtraction operator
    Matrix operator - (const Matrix& leftOp, const Matrix& rightOp)
     {
        const string notSameSize = "ERROR: Matrix subtraction is not defined for for two matrices that are not the same size. \n";
        Matrix difference(rightOp.m, rightOp.n);
        if (leftOp.m != rightOp.m || leftOp.n != rightOp.n)
        {
            cout << notSameSize << endl;
            exit;
        }
        else
        {
            for (int row = 0; row < rightOp.m; row++)
            {
                for (int col = 0; col < rightOp.n; col++)
                {
                    difference.mat[row][col] = leftOp.mat[row][col] - rightOp.mat[row][col];
                    cout << difference.mat[row][col] << endl;
                }
            }
        }
        return difference;
    }

    //overloaded shorthand addition operator
    Matrix& Matrix::operator +=(const Matrix& rightOp)
    {
        const string notSameSize = "ERROR: Matrix addition is not defined for for two matrices that are not the same size. \n";
        if (this->m != rightOp.m || this->n != rightOp.n)
        {
            cout << notSameSize << endl;
            exit;
        }
        else
        {
            for (int row = 0; row < rightOp.m; row++)
            {
                for (int col = 0; col < rightOp.n; col++)
                {
                    this->mat[row][col] += rightOp.mat[row][col];
                }
            }
        }
        return *this;
    }

    //overloaded shorthand addition operator
    Matrix& Matrix::operator -=(const Matrix& rightOp)
    {
        const string notSameSize = "ERROR: Matrix subtraction is not defined for for two matrices that are not the same size. \n";
        if (this->m != rightOp.m || this->n != rightOp.n)
        {
            cout << notSameSize << endl;
            exit;
        }
        else
        {
            for (int row = 0; row < rightOp.m; row++)
            {
                for (int col = 0; col < rightOp.n; col++)
                {
                    mat[row][col] -= rightOp.mat[row][col];
                }
            }
        }
        return *this;
    }
}
    
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;


class Matrix
{
    private:
    int m; //holds row size
    int n; //holds column size
    vector<vector<double>> mat;

    public:
    Matrix() //default constructor
    {
        m = 0;
        n = 0;
        cout << "Default Constructor!" << endl;
    } 
    Matrix(int row, int column) //parameterized constructor
    {
        m = row;
        n = column;
        cout << "Parameterized Constructor!" << endl;
        cout << "Row Size: " << m << " Column Size: " << n << endl;
    }
    
    void populateMatrix() //populate matrix with values
    {
        double value;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Please enter the values for row " << i + 1 << " there should be " << n << " entries." << endl;
                cin >> value;
                mat[i].push_back(value);
            }
        }
    }
    // void printMatrix(); //print contents of matrix

} ;



#endif
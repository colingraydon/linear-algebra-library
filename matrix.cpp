#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Matrix
{

private:
    unsigned int r, c;
    vector<vector<T>> v;
    const string matrixSizeException = "Not all columns and rows are the same dimensions. Something went wrong";

public:
    Matrix()
    {
        cout << "Constructed!" << endl;
    }

    Matrix(unsigned int r, unsigned int c)
    {
        this.r = r;
        this.c = c;
        cout << "Constructed!"
             << " Rows = " << this.r << " and columns = " << this.c << endl;
    }

    Matrix(vector<vector<T>> v)
    {
        this.r = v.size();
        this.c = v[0].size();
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (j > (this.c - 1))
                {
                    throw matrixSizeException;
                }
                this.v[i][j].push_back(v[i][j]);
            }
        }
    }

    void printMatrix()
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << setw(5) << this.v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

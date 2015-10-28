#include <iostream>

using namespace std;

const int M = 5;
const int N = 5;

int** SetColRowZero(int** _arr)
{
    bool row[M] = {false}, col[N] = {false};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (_arr[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }

    for (int i = 0; i < M; i++)
        if (row[i] == 1)
            for (int j = 0; j < N; j++)
                _arr[i][j] = 0;

    for (int j = 0; j < N; j++)
        if (col[j] == 1)
            for (int i = 0; i < M; i++)
                _arr[i][j] = 0;

    return _arr;
}

void PrintMatrix(int** _arr)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << _arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int** matrix = new int*[M];
    for (int i = 0; i < M; i++)
        matrix[i] = new int[N];

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = i + j;

    PrintMatrix(matrix);

    matrix = SetColRowZero(matrix);

    PrintMatrix(matrix);

    delete matrix;

    return 0;
}
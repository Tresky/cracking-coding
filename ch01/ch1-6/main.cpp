#include <iostream>

using namespace std;

const int N = 4;

int** RotateMatrix(int** _arr)
{
    for (int i = 0; i < N / 2; i++)
    {
        int first = i, last = N - i - 1;
        for (int j = first; j < last; j++)
        {
            int curr = j - first;

            swap(_arr[first][j], _arr[last - curr][first]);
            swap(_arr[last - curr][first], _arr[last][last - curr]);
            swap(_arr[last][last - curr], _arr[j][last]);
        }
    }
    return _arr;
}

void PrintMatrix(int** _arr)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << _arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int** image = new int*[N];
    for (int i = 0; i < N; i++)
        image[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            image[i][j] = i + j;

    PrintMatrix(image);

    image = RotateMatrix(image);

    PrintMatrix(image);

    delete image;
    
    return 0;
}
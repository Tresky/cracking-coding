#include <iostream>

using namespace std;

void MergeArrays(int* _arr1, int* _arr2, int _len1, int _len2)
{
    for (int i = _len2 - 1; i > 0; i--)
    {
        if (_arr1[i] <= _arr2[i])
            _arr1[i + _len2] = _arr2[i];
        else if (_arr1[i] > _arr2[i])
            _arr1[i + _len2] = _arr1[i];
    }
}

int main()
{
    int* arr1 = new int[20];
    int* arr2 = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr1[i] = i;
        arr2[i] = i + 10;
    }

    MergeArrays(arr1, arr2, 20, 10);

    for (int i = 0; i < 20; i++)
        cout << arr1[i] << ", ";

    delete[] arr1;
    delete[] arr2;
    return 0;
}
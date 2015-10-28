#include <iostream>
#include <string>

using namespace std;

bool permutation(string _str1, string _str2)
{
    if (_str1.length() != _str2.length())
        return false;

    for (int i = 0; i < _str1.length(); i++)
        if (_str2.find(_str1[i]) == _str2.length())
            return false;
    return true;
}

int main()
{
    string str1 = "hello", str2 = "ehll";
    if (permutation(str1, str2))
        cout << "Is Permutation" << endl;
    else
        cout << "Not Permutation" << endl;
    return 0;
}
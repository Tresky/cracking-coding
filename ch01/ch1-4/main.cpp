#include <iostream>
#include <string>

using namespace std;

string ReplaceSpace(string _str)
{
    for (int i = 0; i < _str.length(); i++)
        if (_str[i] == ' ')
            _str.replace(i, 1, "%20");
    return _str;
}

int main()
{
    string str = "This is my program.";
    cout << "Input: " << str << endl << "Output: " << ReplaceSpace(str) << endl;
    return 0;
}
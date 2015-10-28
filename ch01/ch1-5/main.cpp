#include <iostream>
#include <string>

using namespace std;

string compress(string _str)
{
    string res;
    for (int i = 0; i < _str.length(); i++)
    {
        char c = _str[i];
        int num = 0;
        while (_str[i + num] == c)
            num++;
        
        res += string(c + to_string(num));
        i += --num;
    }
    return res;
}

int main()
{
    string str = "aaabccddddd";
    cout << "Input: " << str << endl;
    cout << "Output: " << compress(str) << endl;
    return 0;
}
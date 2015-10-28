#include <iostream>

using namespace std;

// Consider s1 represented by 'xy'. A valid rotation of
// s1 would be 'yx'.
bool Rotation(string _s1, string _s2)
{
    if (_s1.length() != _s2.length())
        return false;

    string temp = _s1 + _s1;

    if (temp.find(_s2) != string::npos)
        return true;
    else
        return false;
}

int main()
{
    string s1 = "waterbottle", s2 = "erbottlewat";

    if (Rotation(s1, s2))
        cout << s2 << " is a rotation of " << s1 << endl;
    else
        cout << s2 << " is not a rotation of " << s1 << endl;

    return 0;
}
// Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/

#include <iostream>

#define N 1005

using namespace std;

string convert(string s, int numRows)
{
    string str[numRows], ans;
    int j = 0;
    bool x = false;

    if (numRows >= s.size() || numRows == 1)
        return s;

    for (int i = 0; i < s.size(); i++)
    {
        str[j] += s[i];
        if (j == 0)
            x = false;
        if (j == numRows - 1)
            x = true;

        if (x == true)
            j--;
        else
            j++;
    }

    for (int i = 0; i < numRows; i++)
        ans += str[i];

    return ans;
}

int main(int argc, char const *argv[])
{

    string in = "PAYPALISHIRING";

    cout << convert(in, 3) << '\n';

    return 0;
}
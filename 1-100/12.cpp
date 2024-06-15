// Integer to Roman
// https://leetcode.com/problems/integer-to-roman/description/

#include <iostream>

using namespace std;

string intToRoman(int num)
{
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result;
    for (int i = 0; i < 13; ++i)
    {
        while (num >= values[i])
        {
            num -= values[i];
            result += symbols[i];
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int in = 42;
    cout << intToRoman(in) << '\n';

    return 0;
}
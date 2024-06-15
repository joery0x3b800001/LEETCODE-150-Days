// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int sign = 1;
    long long result = 0;

    while (s[i] == ' ')
    {
        i++;
    }

    if (s[i] == '-' || s[i] == '+')
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    while (isdigit(s[i]))
    {
        result = result * 10 + (s[i++] - '0');

        if (result * sign > INT_MAX)
            return INT_MAX;
        if (result * sign < INT_MIN)
            return INT_MIN;
    }

    return result * sign;
}

int main(int argc, char const *argv[])
{

    std::string str = "   -42";
    int result = myAtoi(str);

    cout << result << '\n';
    
    return 0;
}
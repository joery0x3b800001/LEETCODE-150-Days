// Reverse Integer
// https://leetcode.com/problems/reverse-integer/description/

#include <iostream>
#include <climits>

using namespace std;

int reverse(int x)
{
    int reversed = 0;

    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        // Check for overflow
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
            return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
            return 0;

        reversed = reversed * 10 + digit;
    }

    return reversed;
}

int main(int argc, char const *argv[])
{

    // x = 120
    int in = -123;

    cout << reverse(in) << '\n';

    return 0;
}
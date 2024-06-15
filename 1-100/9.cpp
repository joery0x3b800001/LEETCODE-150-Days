// Palindrome Number
// https://leetcode.com/problems/palindrome-number/description/

#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    int original = x;
    long long reverse = 0;

    while (x > 0)
    {
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }

    return original == reverse;
}

int main(int argc, char const *argv[])
{

    int in = 121;

    cout << isPalindrome(in) << '\n';

    return 0;
}
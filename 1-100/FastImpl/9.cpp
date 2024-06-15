// Palindrome Number
// https://leetcode.com/problems/palindrome-number/description/

#include <iostream>
#include <climits>

using namespace std;

int reverse(int x)
{
    int ans = 0;
    while (x)
    {
        if (ans > (INT_MAX - (x % 10)) / 10)
        {
            return 0;
        }
        ans = (ans * 10) + (x % 10);
        x = x / 10;
    }
    return ans;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int y = reverse(x);
    if (x == y)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{

    int in = 121;

    cout << isPalindrome(in) << '\n';

    return 0;
}
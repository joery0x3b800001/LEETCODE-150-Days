// Palindrome Number

// https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
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
};

int main(int argc, char const *argv[])
{
    int x = 121;

    Solution solution;
    cout << solution.isPalindrome(x) << endl;
    return 0;
}
// Factorial Trailing Zeroes

// https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;

    Solution solution;
    cout << solution.trailingZeroes(n) << endl;
    return 0;
}
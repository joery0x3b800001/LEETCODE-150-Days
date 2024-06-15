// Climbing Stairs

// https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int prev1 = 1; // Number of ways to reach step 1
        int prev2 = 2; // Number of ways to reach step 2

        for (int i = 3; i <= n; ++i)
        {
            int current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;

    Solution solution;
    cout << solution.climbStairs(n) << endl;
    return 0;
}
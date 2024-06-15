// Pow(x, n)

// https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;

        double result = 1.0;
        long long exp = n; // Handle integer overflow for the case when n is INT_MIN
        if (exp < 0)
        {
            x = 1 / x;
            exp = -exp;
        }

        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            exp /= 2;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    double x = 2.1;
    int n = 3;

    Solution solution;
    cout << solution.myPow(x, n) << endl;
    return 0;
}
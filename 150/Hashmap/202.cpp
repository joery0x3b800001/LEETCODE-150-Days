// Happy Number

// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 19;
    cout << sol.isHappy(n) << endl;
    return 0;
}
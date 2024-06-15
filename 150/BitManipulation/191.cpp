// Number of 1 Bits

// https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n & 1) // Check if the current bit is 1
                count++;
            n >>= 1; // Right shift n to process the next bit
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int n = 11;

    Solution solution;
    cout << solution.hammingWeight(n) << endl;
    return 0;
}
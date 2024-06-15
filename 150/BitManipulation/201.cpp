// Bitwise AND of Numbers Range

// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        // Find the common prefix by shifting both numbers to the right
        while (left < right)
        {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // Left shift the common prefix to its original position
        return left << shift;
    }
};

int main(int argc, char const *argv[])
{
    int left = 5, right = 7;

    Solution solution;
    cout << solution.rangeBitwiseAnd(left, right) << endl;
    return 0;
}
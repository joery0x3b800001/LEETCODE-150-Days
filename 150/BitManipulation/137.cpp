// Single Number II

// https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (int num : nums)
        {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
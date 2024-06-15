// Single Number

// https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int num : nums)
        {
            result ^= num;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
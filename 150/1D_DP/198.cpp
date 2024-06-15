// House Robber

// https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 7, 9, 3, 1};

    Solution solution;
    int maxAmount = solution.rob(nums);
    cout << "Maximum amount that can be robbed: " << maxAmount << endl;
    return 0;
}
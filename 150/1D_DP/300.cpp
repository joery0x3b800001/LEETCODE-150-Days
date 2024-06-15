// Longest Increasing Subsequence

// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1); // dp[i] represents the length of the LIS ending at index i, initialized to 1

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1); // Update dp[i] if nums[i] can be included in the LIS ending at index i
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); // Return the maximum value in dp array
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution solution;
    int length = solution.lengthOfLIS(nums);
    cout << "Length of the longest increasing subsequence: " << length << endl;
    return 0;
}
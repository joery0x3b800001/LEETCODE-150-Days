// Maximum Subarray

// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0];     // Initialize max_sum to the first element
        int current_sum = nums[0]; // Initialize current_sum to the first element

        for (int i = 1; i < nums.size(); ++i)
        {
            // Update current_sum to be the maximum of the current element or the sum of the current element and the previous sum
            current_sum = max(nums[i], current_sum + nums[i]);
            // Update max_sum to be the maximum of max_sum and current_sum
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum sum of a contiguous subarray: " << sol.maxSubArray(nums) << endl;
    return 0;
}
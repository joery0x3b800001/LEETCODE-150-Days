// Minimum Size Subarray Sum

// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

// https://www.baeldung.com/cs/sliding-window-algorithm

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right)
        {
            sum += nums[right];

            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }

        return (minLength != INT_MAX) ? minLength : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
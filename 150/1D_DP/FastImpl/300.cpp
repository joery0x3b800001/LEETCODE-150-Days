// Longest Increasing Subsequence

// https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> sub;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sub.size() == 0 || nums[i] > sub[sub.size() - 1])
                sub.push_back(nums[i]);
            auto itr = lower_bound(sub.begin(), sub.end(), nums[i]);
            *itr = nums[i];
        }
        return sub.size();
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
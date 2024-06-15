// Longest Consecutive Sequence

// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;
        int last = INT_MIN;

        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (last == nums[i] - 1)
            {
                count++;
                last = nums[i];
            }
            else if (last != nums[i])
            {
                count = 1;
                last = nums[i];
            }
            longest = max(count, longest);
        }
        return longest;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}
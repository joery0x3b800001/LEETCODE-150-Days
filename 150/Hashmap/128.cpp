// Longest Consecutive Sequence

// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums)
        {
            // If the current number is the start of a sequence
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                // Count the length of the consecutive sequence starting from the current number
                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}
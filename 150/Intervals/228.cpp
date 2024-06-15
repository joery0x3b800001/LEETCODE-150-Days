// Summary Ranges

// https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        int n = nums.size();
        if (n == 0)
            return result;
        int start = nums[0], end = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == end + 1)
            {
                end = nums[i];
            }
            else
            {
                if (start == end)
                {
                    result.push_back(to_string(start));
                }
                else
                {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
                start = end = nums[i];
            }
        }

        if (start == end)
        {
            result.push_back(to_string(start));
        }
        else
        {
            result.push_back(to_string(start) + "->" + to_string(end));
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result = sol.summaryRanges(nums);
    for (const string &num : result)
    {
        cout << num << '\n';
    }
    return 0;
}
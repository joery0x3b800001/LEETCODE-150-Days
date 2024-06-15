// Merge Intervals

// https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        vector<int> merged = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > merged[1])
            {
                result.push_back(merged);
                merged = {intervals[i][0], intervals[i][1]};
            }
            else
            {
                merged[0] = min(merged[0], intervals[i][0]);
                merged[1] = max(merged[1], intervals[i][1]);
            }
        }
        result.push_back(merged);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    for (const auto &x : result)
    {
        for (const int &num : x)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
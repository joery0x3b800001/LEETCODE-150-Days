// Merge Intervals

// https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        if (n <= 1)
            return intervals;
        int a = intervals[0][0], b = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= b)
                b = max(b, intervals[i][1]);
            else
            {
                ans.push_back({a, b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a, b});
        return ans;
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
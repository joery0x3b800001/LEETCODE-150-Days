// Insert Interval

// https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        // overlapping part
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i = i + 1;
        }
        res.push_back(newInterval);
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    for (const auto &x : result)
    {
        for (const int &num : x)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
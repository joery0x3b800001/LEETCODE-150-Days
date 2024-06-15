// Minimum Number of Arrows to Burst Balloons

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] > end)
            {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.findMinArrowShots(points) << endl;
    // points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    // cout << sol.findMinArrowShots(points) << endl;
    return 0;
}
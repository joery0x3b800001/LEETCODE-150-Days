// Max Points on a Line

// https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;

        int maxPoints = 0;
        for (int i = 0; i < n; ++i)
        {
            unordered_map<double, int> slopeCount; // Map to store slope count
            int samePoint = 0;
            int localMax = 0;

            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                        ++samePoint;
                    else
                    {
                        double slope = points[i][0] == points[j][0] ? INFINITY : (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                        slopeCount[slope]++;
                        localMax = max(localMax, slopeCount[slope]);
                    }
                }
            }
            maxPoints = max(maxPoints, localMax + samePoint + 1);
        }
        return maxPoints;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

    Solution solution;
    cout << solution.maxPoints(points) << endl;
    return 0;
}
// Triangle

// https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        // Start from the second last row and iterate upwards
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                // Update the current element with the minimum of the two adjacent elements in the next row plus itself
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The top element of the triangle now holds the minimum total
        return triangle[0][0];
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    Solution solution;
    int minTotal = solution.minimumTotal(triangle);
    cout << "Minimum total path sum: " << minTotal << endl;
    return 0;
}
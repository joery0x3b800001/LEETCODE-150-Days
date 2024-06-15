// Minimum Path Sum

// https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the first row
        for (int i = 1; i < n; ++i)
        {
            grid[0][i] += grid[0][i - 1];
        }

        // Initialize the first column
        for (int i = 1; i < m; ++i)
        {
            grid[i][0] += grid[i - 1][0];
        }

        // Iterate though the grid starting from the second row and second column
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                // Update each cell with the minimum of the top and left cells plus the current cell's value
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // The bottom-right cell now contains the minimum path sum
        return grid[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    Solution solution;
    int minSum = solution.minPathSum(grid);
    cout << "Minimum path sum: " << minSum << endl;
    return 0;
}
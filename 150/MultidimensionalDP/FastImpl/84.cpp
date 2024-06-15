// Minimum Path Sum

// https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPathSumRecursive(vector<vector<int>> &grid, int i, int j)
    {
        // Base case: when reaching the bottom-right corner
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return grid[i][j];
        }

        // If we reach the bottom row, we can only move horizontally
        if (i == grid.size() - 1)
        {
            return grid[i][j] + minPathSumRecursive(grid, i, j + 1);
        }

        // If we reach the rightmost column, we can only move vertically
        if (j == grid[0].size() - 1)
        {
            return grid[i][j] + minPathSumRecursive(grid, i + 1, j);
        }

        // Otherwise, we have two choices: move right or move down
        int right = minPathSumRecursive(grid, i, j + 1);
        int down = minPathSumRecursive(grid, i + 1, j);

        // Choose the minimum path
        return grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        return minPathSumRecursive(grid, 0, 0);
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
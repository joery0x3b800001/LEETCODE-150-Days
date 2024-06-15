// Number of Islands

// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++numIslands;
                }
            }
        }

        return numIslands;
    }

private:
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        int numRows = grid.size();
        int numCols = grid[0].size();

        if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] == '0')
            return;

        grid[row][col] = '0'; // Mark as visited

        // Check neighboring cells
        dfs(grid, row - 1, col); // Up
        dfs(grid, row + 1, col); // Down
        dfs(grid, row, col - 1); // Left
        dfs(grid, row, col + 1); // Right
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    Solution solution;

    cout << "Number of islands: " << solution.numIslands(grid) << endl;

    return 0;
}
// Unique Paths II

// https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Initialize dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: if the starting cell is an obstacle, then there's no way to reach the destination
        if (obstacleGrid[0][0] == 1)
            return 0;

        // Set the number of ways to reach the starting cell as 1
        dp[0][0] = 1;

        // Fill in the first column
        for (int i = 1; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1)
                dp[i][0] = 1;
        }

        // Fill in the first row
        for (int j = 1; j < n; ++j)
        {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1)
                dp[0][j] = 1;
        }

        // Fill in the rest of the dp array
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        // The bottom-right cell contains the number of unique paths
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};

    Solution solution;
    int uniquePaths = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << uniquePaths << endl;
    return 0;
}
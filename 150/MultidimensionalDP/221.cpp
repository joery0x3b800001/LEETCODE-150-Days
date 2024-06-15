// Maximal Square

// https://leetcode.com/problems/maximal-square/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        // dp[i][j] represents the side length of the largest square whose bottom right corner is the cell (i, j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int maxSide = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    // dp[i][j] is determined by the minimum of the values in the adjacent cells (up, left, and diagonal up-left)
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution solution;
    cout << solution.maximalSquare(matrix) << endl;
    return 0;
}
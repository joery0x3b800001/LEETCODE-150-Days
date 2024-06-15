// Maximal Square

// https://leetcode.com/problems/maximal-square/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = []()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0; }();

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> psum(1 + m, vector<int>(1 + n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    psum[i + 1][j + 1] = 1 + min(psum[i + 1][j], min(psum[i][j + 1], psum[i][j]));
                    ans = max(ans, psum[i + 1][j + 1]);
                }
            }
        }
        return ans * ans;
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
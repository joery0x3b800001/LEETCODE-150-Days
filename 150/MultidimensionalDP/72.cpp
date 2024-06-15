// Edit Distance

// https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        // Create a 2D dp table to store the minimum edit distance
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the first row and first column of the dp table
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j)
        {
            dp[0][j] = j;
        }

        // Fill in the dp table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match, no additional operation needed
                }
                else
                {
                    // Minimum of insert, delete, or replace
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], // Replace
                                        dp[i][j - 1],     // Insert
                                        dp[i - 1][j]});   // Delete
                }
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    string word1 = "horse";
    string word2 = "ros";
    Solution solution;
    cout << solution.minDistance(word1, word2) << endl;
    return 0;
}
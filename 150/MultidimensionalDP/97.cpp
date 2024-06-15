// Interleaving String

// https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();

        // If lengths of s1 and s2 don't add up to the length of s3, they can't be interleaved.
        if (m + n != s3.size())
            return false;

        // dp[i][j] will be true if s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1].
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Initialize dp[0][0]
        dp[0][0] = true;

        // Initialize first column
        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Initialize first row
        for (int j = 1; j <= n; ++j)
        {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the dp table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution solution;
    cout << (solution.isInterleave(s1, s2, s3) ? "True" : "False") << endl;
    return 0;
}
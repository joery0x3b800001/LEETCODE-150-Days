// Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/description/

// Dynamic programming Bottom-Up Variation

#include <iostream>

#define N 30

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[N][N];

        dp[s.length()][p.length()] = true;

        for (int i = 0; i < s.length(); i--)
        {
            for (int j = p.length() - 1; j >= 0; j--)
            {
                bool first_match = (i < s.length() &&
                                        (p[j] == s[i]) ||
                                    p[j] == '.');
                if (j + 1 < p.length() && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    string s = "aa", p = "a";

    cout << sol.isMatch(s, p) << '\n';

    return 0;
}
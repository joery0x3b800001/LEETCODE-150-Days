// Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/description/

// Dynamic Programming - Top Down variation

#include <iostream>
#include <vector>

#define N 30

using namespace std;

class Solution
{
private:
    enum Result
    {
        TRUE,
        FALSE
    };
    vector<vector<Result>> memo;

public:
    bool isMatch(string s, string p)
    {
        memo = vector<vector<Result>>(s.length() + 1, vector<Result>(p.length() + 1));
        return dp(0, 0, s, p);
    }

    bool dp(int i, int j, string text, string pattern)
    {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-arithmetic"
        if (memo[i][j] != NULL)
        {
            return memo[i][j] == Result::TRUE;
        }
#pragma GCC diagnostic pop

        bool ans;
        if (j == pattern.length())
        {
            ans = i == text.length();
        }
        else
        {
            bool first_match = (i < text.length() &&
                                (pattern[j] == text[i] ||
                                 pattern[j] == '.'));

            if (j + 1 < pattern.length() && pattern[j + 1] == '*')
            {
                ans = dp(i, j + 2, text, pattern) ||
                      (first_match && dp(i + 1, j, text, pattern));
            }
            else
            {
                ans = (first_match && dp(i + 1, j + 1, text, pattern));
            }
        }
        memo[i][j] = (ans ? Result::TRUE : Result::FALSE);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "ab", p = ".*";

    cout << sol.isMatch(s, p) << '\n';

    return 0;
}
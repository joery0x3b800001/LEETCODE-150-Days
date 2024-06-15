// Word Break

// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] represents if s[0...i] can be segmented into words from the dictionary
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && dict.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution solution;
    bool canBreak = solution.wordBreak(s, wordDict);
    cout << "Can the string be segmented into words from the dictionary? " << (canBreak ? "Yes" : "No") << endl;
    return 0;
}
// Is Subsequence

// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int j = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[j])
                j++;
        }

        return (j == s.size());
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    string s = "abc";
    string t = "ahbgdc";

    if (sol.isSubsequence(s, t))
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
    return 0;
}
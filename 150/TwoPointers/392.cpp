// Is Subsequence

// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sIndex = 0, tIndex = 0; // Index for s and t
        while (sIndex < s.length() && tIndex < t.length())
        {
            if (s[sIndex] == t[tIndex])
            {
                sIndex++; // Move to next character in s
            }
            tIndex++; // Always move to next character in t
        }
        return sIndex == s.length(); // If i equals length of s, then all characters
                                     //  of s have been found in t.
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
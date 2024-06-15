// Isomorphic Strings

// https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        for (size_t i = 0; i < s.length(); ++i)
        {
            char sChar = s[i];
            char tChar = t[i];

            // Check if the characters in s has already been mapped to different character in t
            if (sMap.find(sChar) != sMap.end() && sMap[sChar] != tChar)
            {
                return false;
            }
            else
            {
                sMap[sChar] = tChar; // Otherwise, map sChar to tChar.
            }

            // Check if the characters in t has already been mapped to different character in s
            if (tMap.find(tChar) != tMap.end() && tMap[tChar] != sChar)
            {
                return false;
            }
            else
            {
                tMap[tChar] = sChar;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "foo";
    string t = "bar";
    cout << sol.isIsomorphic(s, t) << endl;
    return 0;
}
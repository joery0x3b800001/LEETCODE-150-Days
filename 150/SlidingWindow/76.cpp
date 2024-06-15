// Minimum Window Substring

// https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> charCount;
        for (char c : t)
            charCount[c]++;

        int left = 0, right = 0, minLen = INT_MAX, minStart = 0, count = t.size();

        while (right < s.size())
        {
            if (charCount[s[right]] > 0)
                count--;
            charCount[s[right]]--;
            right++;

            while (count == 0)
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    minStart = left;
                }

                if (charCount[s[left]] == 0)
                    count++;
                charCount[s[left]]++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl;
}
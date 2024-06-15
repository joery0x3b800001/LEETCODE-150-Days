// Longest Palindromic Substring

// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0;     // Start index of the longest palindrome found so far
        int maxLength = 1; // Length of the longest palindrome found so far

        int n = s.size();

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                int currLength = right - left + 1;
                if (currLength > maxLength)
                {
                    start = left;
                    maxLength = currLength;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; ++i)
        {
            // For odd length palindromes
            expandAroundCenter(i, i);
            // For even length palindromes
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};

int main(int argc, char const *argv[])
{
    string s = "cbba";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}
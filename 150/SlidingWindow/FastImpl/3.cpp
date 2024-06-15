// Longest Substring Without Repeating Characters

// https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        int arr[500];
        for (int i = 0; i < 500; i++)
        {
            arr[i] = -1;
        }

        int start = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[s[i]] == -1)
            {
                arr[s[i]] = i;
            }
            else
            {
                len = max(len, i - start);
                if (arr[s[i]] + 1 > start)
                {
                    start = arr[s[i]] + 1;
                }
                arr[s[i]] = i;
            }
        }

        len = max(len, n - start);
        return len;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    string in = "abcabcbb";

    cout << sol.lengthOfLongestSubstring(in) << '\n';

    return 0;
}

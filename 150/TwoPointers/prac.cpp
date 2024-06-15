#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        while (!isalnum(s[left]) && left < right)
        {
            left++;
        }

        while (!isalnum(s[right]) && left < right)
        {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
    }
    return true;
}

bool isSubsequence(string s, string t)
{
    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length())
    {
        if (s[i] == s[j])
        {
            i++;
        }
        j++;
    }
    return i == s.length();
}
// Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle)
{
    int haystackLen = haystack.length();
    int needleLen = needle.length();

    if (needleLen == 0)
    {
        return 0;
    }

    for (int i = 0; i <= haystackLen - needleLen; ++i)
    {
        int j;
        for (j = 0; j < needleLen; ++j)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }
        if (j == needleLen)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{

    string haystack = "sadbutsad", needle = "sad";
    string haystack1 = "leetcode", needle1 = "leeto";

    cout << strStr(haystack, needle) << endl;
    cout << strStr(haystack1, needle1) << endl;
    return 0;
}
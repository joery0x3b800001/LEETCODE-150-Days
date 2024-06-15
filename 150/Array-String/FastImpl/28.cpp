// Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle)
{
    if (haystack.size() < needle.size())
        return -1;
    for (int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        if (haystack.substr(0, needle.size()) == needle)
            return i;
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
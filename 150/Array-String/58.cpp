// Length of Last Word
// https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s)
{
    int length = 0;
    int i = s.length() - 1; // Start from the end of the string

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }

    // Count the characters until a space or the beginning of the string
    while (i >= 0 && s[i] != ' ')
    {
        length++;
        i--;
    }

    return length;
}

int main(int argc, char const *argv[])
{
    string s = "   fly me   to   the moon  ";

    cout << lengthOfLastWord(s) << endl;
    return 0;
}
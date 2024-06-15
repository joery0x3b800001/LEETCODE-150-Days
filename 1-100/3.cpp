// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// https://www.baeldung.com/java-longest-substring-without-repeated-characters

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> visited;

    string output = "";
    for (int start = 0, end = 0; end < s.length(); end++)
    {
        char currChar = s[end];
        if (visited.find(currChar) != visited.end())
        {
            start = max(visited[currChar] + 1, start);
        }

        if (output.length() < end - start + 1)
        {
            output = s.substr(start, end - start + 1);
        }

        visited[currChar] = end;
    }
    return output.length();
}

int main(int argc, char const *argv[])
{
    string in = "abcabcbb";

    cout << lengthOfLongestSubstring(in) << '\n';

    return 0;
}

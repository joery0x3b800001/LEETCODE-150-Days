// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    // If the input array is empty, return an empty string
    if (strs.empty())
        return "";

    // Initialize the longest common prefix as the first string in the array
    std::string longestPrefix = strs[0];

    // Iterate through the remaining strings in the array
    for (int i = 1; i < strs.size(); ++i)
    {
        // Compare each character of the current string with the current longest common prefix
        int j = 0;
        while (j < longestPrefix.length() && j < strs[i].length() && longestPrefix[j] == strs[i][j])
        {
            ++j;
        }
        // Update the longest common prefix to be the common prefix found so far
        longestPrefix = longestPrefix.substr(0, j);
        // If the longest common prefix becomes empty, break the loop
        if (longestPrefix.empty())
            break;
    }

    return longestPrefix;
}

int main(int argc, char const *argv[])
{

    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << '\n';

    return 0;
}
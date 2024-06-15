// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    std::string res = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        for (int j = 0; j < strs.size(); j++)
        {
            if ((i == strs[j].length()) || (strs[j][i] != strs[0][i]))
            {
                return res;
            }
        }
        res = res + strs[0][i];
    }
    return res;
}

int main(int argc, char const *argv[])
{

    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << '\n';

    return 0;
}
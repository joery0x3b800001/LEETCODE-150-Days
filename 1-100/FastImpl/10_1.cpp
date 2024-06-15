// Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/description/

// Recursion

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();
        bool first_match = (!s.empty() &&
                                p[0] == s[0] ||
                            p[0] == '.');
        if (p.length() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) ||
                   (first_match && isMatch(s.substr(1), p));
        }
        else
        {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    string s = "ab", p = ".*";

    cout << sol.isMatch(s, p) << '\n';

    return 0;
}
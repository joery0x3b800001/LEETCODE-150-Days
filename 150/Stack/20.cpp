// Valid Parentheses

// https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "()[]{}";
    cout << sol.isValid(s) << endl;
    return 0;
}
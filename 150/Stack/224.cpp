// Basic Calculator

// https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> stk;
        int result = 0;
        int num = 0;
        int sign = 1;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '+')
            {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-')
            {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(')
            {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result += sign * num;
                num = 0;
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
            }
        }

        if (num != 0)
        {
            result += sign * num;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(s) << endl;
    return 0;
}
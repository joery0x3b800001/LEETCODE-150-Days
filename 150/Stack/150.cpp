// Evaluate Reverse Polish Notation

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                if (token == "+")
                    s.push(operand1 + operand2);
                else if (token == "-")
                    s.push(operand1 - operand2);
                else if (token == "*")
                    s.push(operand1 * operand2);
                else if (token == "/")
                    s.push(operand1 / operand2);
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}
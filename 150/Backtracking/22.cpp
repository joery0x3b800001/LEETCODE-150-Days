// Generate Parentheses

// https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generateParenthesisRecursive(result, "", n, n);
        return result;
    }

    void generateParenthesisRecursive(vector<string> &result, string current, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(current);
            return;
        }

        if (left > 0)
        {
            generateParenthesisRecursive(result, current + '(', left - 1, right);
        }

        if (right > left)
        {
            generateParenthesisRecursive(result, current + ')', left, right - 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 3;
    vector<string> result = sol.generateParenthesis(n);

    cout << "All valid combinations of " << n << " pairs of parentheses are:" << endl;
    for (const string &str : result)
    {
        cout << str << endl;
    }

    return 0;
}
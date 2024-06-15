// Combinations

// https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, n, k, 1);
        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &current, int n, int k, int start)
    {
        if (current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            current.push_back(i);
            backtrack(result, current, n, k, i + 1);
            current.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> result = sol.combine(n, k);

    cout << "All combinations of " << k << " numbers out of 1 ... " << n << " are:" << endl;
    for (const auto &combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
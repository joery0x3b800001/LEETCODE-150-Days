// Combination Sum

// https://leetcode.com/problems/combination-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, candidates, target, 0);
        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &current, const vector<int> &candidates, int target, int start)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i)
        {
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i); // Reuse elements
            current.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "All combinations summing up to " << target << " are:" << endl;
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
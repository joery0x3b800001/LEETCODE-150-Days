// Combinations

// https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        dfs(n, k, 1, {}, ans);
        return ans;
    }

    void dfs(int n, int k, int s, vector<int>&& path, vector<vector<int>>& ans)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }

        for (int i = s; i <= n; ++i)
        {
            path.push_back(i);
            dfs(n, k, i + 1, move(path), ans);
            path.pop_back();
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
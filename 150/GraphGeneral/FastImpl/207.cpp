// Course Schedule

// https://leetcode.com/problems/course-schedule/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<pair<int, int>> visited(numCourses, {0, 0});
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i].first)
            {
                if (dfs(i, visited, adj))
                    return false;
            }
        }
        return true;
    }

    bool dfs(int node, vector<pair<int, int>> &visited, vector<int> adj[])
    {
        visited[node] = {1, 1};
        for (auto it : adj[node])
        {
            if (!visited[it].first)
            {
                if (dfs(it, visited, adj))
                    return true;
            }
            else if (visited[it].second)
            {
                return true;
            }
        }
        visited[node] = {1, 0};
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> prerequisites = {{1, 0}};
    int numCourses = 2;

    Solution solution;
    cout << solution.canFinish(numCourses, prerequisites) << endl;

    return 0;
}
// Course Schedule

// https://leetcode.com/problems/course-schedule/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build adjacency list representation of the graph
        unordered_map<int, vector<int>> adjList;
        for (const auto &prereq : prerequisites)
        {
            adjList[prereq[1]].push_back(prereq[0]);
        }

        // Array to keep track of visited nodes during DFS
        vector<int> visited(numCourses, 0); // 0: not visited, 1: being visited, 2: visited

        // Perform DFS on each node
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(adjList, visited, i))
            {
                return false; // Cycle detected
            }
        }
        return true; // No cycle detected
    }

    bool dfs(unordered_map<int, vector<int>> &adjList, vector<int> &visited, int course)
    {
        // If the node is being visited, cycle dectected
        if (visited[course] == 1)
        {
            return false;
        }

        // If the node has been visited before, no need to visit again
        if (visited[course] == 2)
        {
            return true;
        }

        // Mark the node as being visited
        visited[course] = 1;

        // Visit all neighbors of the current node
        for (int neighbor : adjList[course])
        {
            if (!dfs(adjList, visited, neighbor))
            {
                return false; // Cycle detected
            }
        }

        // Mark the node as visited
        visited[course] = 2;
        return true;
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
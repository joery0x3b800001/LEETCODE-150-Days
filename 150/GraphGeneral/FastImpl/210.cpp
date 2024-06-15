// Course Schedule II

// https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150

// This program utilizes Kahn's Algorithm to find the topological order of the courses.
// The findOrder function constructs the adjacency list and computes in-degrees of each
// course before performing the topological sort using a queue. Finally, it returns the
// order if a valid course schedule is possible, otherwise an empty vector indicating
// impossibility.

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Build adjacency list representation of the graph
        unordered_map<int, vector<int>> adjList;
        for (const auto &prereq : prerequisites)
        {
            adjList[prereq[1]].push_back(prereq[0]);
        }

        // Array to keep track of in-degrees of nodes
        vector<int> inDegrees(numCourses, 0);
        for (const auto &prereq : prerequisites)
        {
            inDegrees[prereq[0]]++;
        }

        // Initialize a queue for Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }

        // Array to store the order of courses
        vector<int> order;

        // Kahn's Algorithm
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neighbor : adjList[course])
            {
                if (--inDegrees[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // If not all courses are included in the order, return an empty vector
        if (order.size() != numCourses)
        {
            return {};
        }

        return order;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;

    Solution solution;
    vector<int> result = solution.findOrder(numCourses, prerequisites);
    for (const auto &x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
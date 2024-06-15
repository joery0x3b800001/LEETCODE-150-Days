// Course Schedule II

// https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Adjacency list representation of the graph
        vector<vector<int>> graph(numCourses);
        // In-degree of each course
        vector<int> inDegree(numCourses, 0);
        // Topological order of courses
        vector<int> order;

        // Contruct the graph and compute in-degrees
        for (const auto &pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // Initialize a queue for Kahn's Algorithm
        queue<int> q;

        // Add courses with in-degree 0 to the queue
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);

            // Reduce in-degree of adjacent courses
            for (int adjCourse : graph[course])
            {
                if (--inDegree[adjCourse] == 0)
                {
                    q.push(adjCourse);
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
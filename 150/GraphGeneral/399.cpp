// Evaluate Division

// https://leetcode.com/problems/evaluate-division/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); ++i)
        {
            const string &A = equations[i][0];
            const string &B = equations[i][1];
            const double value = values[i];
            graph[A][B] = value;
            graph[B][A] = 1.0 / value; // Inverse relation
        }

        vector<double> results;
        for (const auto &query : queries)
        {
            const string &X = query[0];
            const string &Y = query[1];
            if (!graph.count(X) || !graph.count(Y))
            {
                results.push_back(-1.0); // One or both nodes not found
            }
            else if (X == Y)
            {
                results.push_back(1.0); // Same node, value is 1
            }
            else
            {
                unordered_set<string> visited;
                results.push_back(dfs(graph, X, Y, visited));
            }
        }

        return results;
    }

private:
    double dfs(unordered_map<string, unordered_map<string, double>> &graph, const string &curr, const string &target, unordered_set<string> &visited)
    {
        if (curr == target)
            return 1.0;
        visited.insert(curr);
        for (const auto &neighbor : graph[curr])
        {
            if (!visited.count(neighbor.first))
            {
                double result = dfs(graph, neighbor.first, target, visited);
                if (result != -1.0)
                {
                    return result * neighbor.second;
                }
            }
        }
        return -1.0;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    Solution sol;
    vector<double> results = sol.calcEquation(equations, values, queries);

    cout << "Results:" << endl;
    for (double result : results)
    {
        cout << result << endl;
    }

    return 0;
}
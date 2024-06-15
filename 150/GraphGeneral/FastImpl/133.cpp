// Clone Graph

// https://leetcode.com/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150

// https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph
// https://en.wikipedia.org/wiki/Object_copying#Deep_copy

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> visited;
        queue<Node *> q;

        // Clone the first node and add it to the queue
        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        q.push(node);

        // Perform BFS to clone the graph
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            // Iterate through the neighbours of the current node
            for (Node *neighbor : curr->neighbors)
            {
                // If the neighbor is not visited, clone it and add it to the queue
                if (visited.find(neighbor) == visited.end())
                {
                    Node *cloneNeighbor = new Node(neighbor->val);
                    visited[neighbor] = cloneNeighbor;
                    q.push(neighbor);
                }
                // Add the clone of the neighbor to the clone of the current node's neighbors
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        return cloneNode;
    }
};

// Test the solution
int main()
{
    // Example graph: [[2,4],[1,3],[2,4],[1,3]]
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution sol;
    Node *clonedGraph = sol.cloneGraph(node1);

    // Output the cloned graph
    cout << "Cloned graph neighbors:" << endl;
    for (Node *node : clonedGraph->neighbors)
    {
        cout << "Node " << clonedGraph->val << " -> ";
        for (Node *neighbor : node->neighbors)
        {
            cout << neighbor->val << " ";
        }
        cout << endl;
    }

    return 0;
}
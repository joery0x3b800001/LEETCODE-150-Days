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
        return clone(node, visited);
    }

private:
    Node *clone(Node *node, unordered_map<Node *, Node *> &visited)
    {
        // If the node has been visited, return its clone
        if (visited.find(node) != visited.end())
            return visited[node];

        // Create a clone of the current node
        Node *cloneNode = new Node(node->val);

        // Mark the node as visited
        visited[node] = cloneNode;

        // Clone each neighbor recursively
        for (Node *neighbor : node->neighbors)
        {
            cloneNode->neighbors.push_back(clone(neighbor, visited));
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
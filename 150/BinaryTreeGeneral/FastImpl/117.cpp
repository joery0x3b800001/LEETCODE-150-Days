// Populating Next Right Pointers in Each Node II

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (q.size() != 1)
        {
            Node *p = q.front();
            q.pop();

            if (p == NULL)
            {
                q.push(NULL);
                continue;
            }
            else
                p->next = q.front();

            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
        }

        return root;
    }
};

int main(int argc, char const *argv[])
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    // Create an instance of the solution
    Solution solution;

    // Connect the nodes
    Node *connectedRoot = solution.connect(root);

    // Print the next pointers of each node
    Node *current = connectedRoot;
    while (current != nullptr)
    {
        Node *temp = current;
        while (temp != nullptr)
        {
            cout << temp->val << ", ";
            temp = temp->next;
        }
        cout << "#, ";
        current = current->left; // Move to the next level
    }
    std::cout << std::endl;

    // Clean up
    // (Skipping the cleanup code for simplicity)

    return 0;
}
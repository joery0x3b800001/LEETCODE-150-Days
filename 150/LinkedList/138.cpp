// Copy List with Random Pointer

// https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        unordered_map<Node *, Node *> copiedNodes;

        // First pass: create a copy of each node without random pointer and store mapping in hashmap
        Node *curr = head;
        while (curr)
        {
            copiedNodes[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: assign next and random pointers for the copied nodes
        curr = head;
        while (curr)
        {
            copiedNodes[curr]->next = copiedNodes[curr->next];
            copiedNodes[curr]->random = copiedNodes[curr->random];
            curr = curr->next;
        }
        return copiedNodes[head];
    }
};

// Utility function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        cout << "[" << head->val;
        if (head->random)
            cout << "," << head->random->val << "]";
        else
            cout << ",null]";
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // Create a sample linked list with random pointers
    Node *head = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    head->next = second;
    head->random = NULL;
    second->next = third;
    second->random = head;
    third->next = fourth;
    third->random = fifth;
    fourth->next = fifth;
    fourth->random = third;
    fifth->random = head;

    // Create an instance of Solution
    Solution solution;

    // Call copyRandomList function
    Node *copiedListHead = solution.copyRandomList(head);

    // Print the original and copied linked lists
    cout << "Original List:" << endl;
    printList(head);

    cout << "Copied List:" << endl;
    printList(copiedListHead);

    return 0;
}
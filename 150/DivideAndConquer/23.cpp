// Merge k Sorted Lists

// https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Comparison function for priority queue
struct CompareNodes
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap based on node values
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, CompareNodes> pq;

        // Push the heads of all lists into the priority queue
        for (ListNode *list : lists)
        {
            if (list)
            {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        // Merge nodes from the priority queue
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next)
            {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};

// Utility function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution sol;

    // Example lists
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    // Vector of lists
    vector<ListNode *> lists = {l1, l2, l3};

    // Merge lists
    ListNode *mergedList = sol.mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
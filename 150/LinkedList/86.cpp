// Partition List

// https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150

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

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lessHead = new ListNode(0);              // Head of the list with nodes less than x
        ListNode *greaterOrEqualHead = new ListNode(0);    // Head of the list with nodes greater or equal to x
        ListNode *lessTail = lessHead;                     // Tail pointer for the list with nodes less than x
        ListNode *greaterOrEqualTail = greaterOrEqualHead; // Tail pointer for the list with nodes greater or equal to x

        while (head != nullptr)
        {
            if (head->val < x)
            {
                lessTail->next = head;
                lessTail = lessTail->next;
            }
            else
            {
                greaterOrEqualTail->next = head;
                greaterOrEqualTail = greaterOrEqualTail->next;
            }
            head = head->next;
        }

        greaterOrEqualTail->next = nullptr;        // Terminate the list with nodes greater or equal to x
        lessTail->next = greaterOrEqualHead->next; // Connect the two lists

        return lessHead->next; // Return the head of the combined list
    }
};

// Utility function to print the linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    int x = 3;
    head = sol.partition(head, x);

    cout << "After partitioning the list at " << x << " position: ";
    printList(head);

    return 0;
}
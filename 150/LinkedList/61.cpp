// Rotate List

// https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head; // If the list is empty or no rotation needed

        int length = 1; // Length of the list
        ListNode *tail = head;

        // Calculate the length of the list and find the tail node
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }

        // Adjust k to be within the range of the list length
        k = k % length;

        if (k == 0)
            return head; // No rotation needed

        // Find the new head and new tail positions after rotation
        ListNode *newTail = head;
        for (int i = 0; i < length - k - 1; ++i)
        {
            newTail = newTail->next;
        }
        ListNode *newHead = newTail->next;

        // Perform the rotation
        newTail->next = nullptr; // Cut the list at the new tail position
        tail->next = head;       // Connect the original tail to the original head

        return newHead;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    int k = 2;
    head = sol.rotateRight(head, k);

    cout << "After rotating the list " << k << " positions to the right: ";
    printList(head);

    return 0;
}
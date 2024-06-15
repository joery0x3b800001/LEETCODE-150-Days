// Remove Duplicates from Sorted List II

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head; // If list is empty or has only one node

        ListNode *dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr)
        {
            bool isDuplicate = false;

            // Move curr to the end of duplicates
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                isDuplicate = true;
            }

            if (isDuplicate) // Remove duplicates
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
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
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

    cout << "After removing the duplicates: ";
    printList(head);

    return 0;
}
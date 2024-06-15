// Reverse Linked List II

// https://leetcode.com/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || left == right)
            return head;

        ListNode *temp = new ListNode(0);
        temp->next = head;

        ListNode *prev = temp;
        for (int i = 0; i < left - 1; ++i)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        ListNode *next = nullptr;
        for (int i = 0; i < right - left; ++i)
        {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return temp->next;
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
    int left = 2;
    int right = 4;
    head = sol.reverseBetween(head, left, right);

    cout << "Reversed List from position " << left << " to " << right << ": ";
    printList(head);

    return 0;
}
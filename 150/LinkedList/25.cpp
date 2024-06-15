// Reverse Nodes in k-Group

// https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *prev = temp;
        ListNode *curr = head;
        int count = 0;

        while (curr)
        {
            count++;
            if (count % k == 0)
            {
                prev = reverse(prev, curr->next);
                curr = prev->next;
            }
            else
            {
                curr = curr->next;
            }
        }

        return temp->next;
    }

private:
    ListNode *reverse(ListNode *prev, ListNode *next)
    {
        ListNode *last = prev->next;
        ListNode *curr = last->next;
        while (curr != next)
        {
            last->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = last->next;
        }
        return last;
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
    head = sol.reverseKGroup(head, k);

    cout << "Reversed List from position for k = " << k << ": ";
    printList(head);

    return 0;
}
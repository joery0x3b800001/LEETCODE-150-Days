// Merge Two Sorted Lists

// https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = new ListNode(0);
        ListNode *current = result;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
            }
            else
            {
                current->next = new ListNode(list2->val);
                current = current->next;
                list2 = list2->next;
            }
        }

        // If either list1 or list2 has remaining nodes
        while (list1 != NULL)
        {
            current->next = new ListNode(list1->val);
            current = current->next;
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }

        return result->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *result = sol.mergeTwoLists(list1, list2);

    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
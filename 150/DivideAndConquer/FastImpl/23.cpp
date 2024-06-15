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

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto list : lists)
        {
            while (list != NULL)
            {
                pq.push(list->val);
                list = list->next;
            }
        }
        if (pq.empty())
        {
            return nullptr;
        }
        ListNode *temp;
        if (!pq.empty())
        {
            ans = new ListNode(0);
            ans->val = pq.top();
            temp = ans;
            pq.pop();
        }
        while (!pq.empty())
        {
            ListNode *temp1 = new ListNode(pq.top());
            pq.pop();
            temp->next = temp1;
            temp = temp1;
        }
        return ans;
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
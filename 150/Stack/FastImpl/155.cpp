// Min Stack

// https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
    struct Node
    {
        int val;
        int minVal;
        Node *next;

        Node(int v, int minV, Node *n)
            : val(v), minVal(minV), next(n)
        {
        }
    };
    Node *head;

public:
    MinStack()
    {
        head = nullptr;
    }

    void push(int val)
    {
        if (head == nullptr)
            head = new Node(val, val, nullptr);
        else
            head = new Node(val, min(head->minVal, val), head);
    }

    void pop()
    {
        if (head == nullptr)
            std::cerr << "Stack empty! Cannot pop.";
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[])
{
    MinStack *sol = new MinStack();
    sol->push(-2);
    sol->push(0);
    sol->push(-3);
    cout << sol->getMin() << " ";
    sol->pop();
    cout << sol->top() << " ";
    cout << sol->getMin();
    cout << endl;
    return 0;
}
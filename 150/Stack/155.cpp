// Min Stack

// https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.empty())
        {
            stack.push({val, val});
        }
        else
        {
            int minSoFar = min(val, stack.top().second);
            stack.push({val, minSoFar});
        }
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }

private:
    std::stack<std::pair<int, int>> stack; // {elem, minSoFar}
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
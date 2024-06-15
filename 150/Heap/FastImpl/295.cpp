// Find Median from Data Stream

// https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
public:
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> higher;

    MedianFinder()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    void addNum(int num)
    {
        if (lower.empty())
        {
            lower.push(num);
            return;
        }

        if (lower.size() > higher.size())
        {
            if (lower.top() > num)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
            else
            {
                higher.push(num);
            }
        }
        else
        {
            if (num > higher.top())
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
            else
            {
                lower.push(num);
            }
        }
    }

    double findMedian()
    {
        double result = 0.0;

        if (lower.size() == higher.size())
        {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        }
        else
        {
            if (lower.size() > higher.size())
            {
                result = lower.top();
            }
            else
            {
                result = higher.top();
            }
        }

        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, char const *argv[])
{
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);                    // arr = [1]
    medianFinder->addNum(2);                    // arr = [1, 2]
    cout << medianFinder->findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder->addNum(3);                    // arr[1, 2, 3]
    cout << medianFinder->findMedian() << endl; // return 2.0

    return 0;
}
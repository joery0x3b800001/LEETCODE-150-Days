// Sqrt(x)

// https://leetcode.com/problems/sqrtx/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x; // Base case: if x is 0 or 1, return x

        int left = 1, right = x;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // Check if mid*mid is equal to x
            if (mid == x / mid)
            {
                return mid;
            }
            else if (mid < x / mid)
            {
                // If mid*mid is less than x, search in the right half
                left = mid + 1;
            }
            else
            {
                // If mid*mid is greater than x, search in the left half
                right = mid - 1;
            }
        }
        // If we don't find an exact match, return the floor of the square root
        return right;
    }
};

int main(int argc, char const *argv[])
{
    int x = 8;

    Solution solution;
    cout << solution.mySqrt(x) << endl;
    return 0;
}
// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int area = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    area += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    area += rightMax - height[right];
                }
                right--;
            }
        }
        return area;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    // vector<int> arr = {4, 2, 0, 3, 2, 5};
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << sol.trap(arr) << endl;
    return 0;
}
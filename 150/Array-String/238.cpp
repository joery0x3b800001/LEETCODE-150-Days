// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n, 1);

        // Compute prefix product
        int prefixProduct = 1;
        for (int i = 0; i < n; ++i)
        {
            output[i] *= prefixProduct;
            prefixProduct *= nums[i];
        }

        // Compute suffix product.
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            output[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return output;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    auto res = sol.productExceptSelf(nums);

    for (int x : res)
    {
        cout << x << ' ';
    }

    return 0;
}
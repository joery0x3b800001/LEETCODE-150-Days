// Maximum Sum Circular Subarray

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int n = A.size();
        int max_sum = A[0];   // Initialize maximum sum to the first element
        int min_sum = A[0];   // Initialize minimum sum to the first element
        int total_sum = A[0]; // Initialize total sum to the first element
        int curr_max = A[0];  // Initialize current max sum to the first element
        int curr_min = A[0];  // Initialize current min sum to the first element

        // Kadane's algorithm to find maximum and minimum sum of non-circular subarray
        for (int i = 1; i < n; ++i)
        {
            curr_max = max(A[i], curr_max + A[i]);
            max_sum = max(max_sum, curr_max);
            curr_min = min(A[i], curr_min + A[i]);
            min_sum = min(min_sum, curr_min);
            total_sum += A[i];
        }

        // If all elements are negative, return the maximum element
        if (max_sum < 0)
        {
            return max_sum;
        }

        // Calculate maximum sum of circular subarray
        int circular_max_sum = total_sum - min_sum;

        // Return maximum of non-circular and circular maximum sum
        return max(max_sum, circular_max_sum);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> A = {1, -2, 3, -2};
    cout << "Maximum sum of a circular subarray: " << sol.maxSubarraySumCircular(A) << endl;
    return 0;
}
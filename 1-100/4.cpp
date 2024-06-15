// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<double> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        result.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        result.push_back(nums2[i]);
    }

    sort(result.begin(), result.end());

    return (result.size() % 2 == 0) ? (result[result.size() / 2 - 1] + result[result.size() / 2]) / 2 : result[floor(result.size() / 2)];
}

int main(int argc, char const *argv[])
{
    // nums1 = [1,3], nums2 = [2]
    vector<int> arr1, arr2;
    arr1 = {1, 2}; 
    arr2 = {3, 4};

    cout << findMedianSortedArrays(arr1, arr2) << '\n';

    return 0;
}
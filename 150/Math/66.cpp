// Plus One

// https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; --i)
        {
            // Add one to the current digit
            digits[i]++;
            // If there is no carry, return the digits
            if (digits[i] <= 9)
                return digits;
            // Otherwise, set the current digits to 0 and continue the loop
            digits[i] = 0;
        }
        // If we reach here, it means we have a carry after adding one to the most significant digit
        // In this case, we need to insert a new digit at the beginning of the array and set it to 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> digits = {4, 3, 2, 1};

    Solution solution;
    vector<int> result = solution.plusOne(digits);
    for (const auto &x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
// Maximum Subarray

// https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int init = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

// Function to extract digit value from a character
int digit(char c)
{
    return c & 15;
}

// Function to check if a character is a digit
bool isDigit(char c)
{
    return '0' <= c && c <= '9';
}

int in = []
{
    std::ofstream out("user.out"); // Redirect cout to user.out
    std::cout.rdbuf(out.rdbuf());

    int ans, sum;
    bool _neg;

    // Read input line by line
    for (std::string s; std::getline(std::cin, s); std::cout << '\n')
    {
        ans = -1e9, sum = 0; // Initialize answer and sum for each input line

        for (int _i = 1, _n = s.length(), v; _i < _n; ++_i)
        {
            _neg = false; // Initialize flag to indicate negative number

            if (s[_i] == '-')
            {                // Check for negative sign
                ++_i;        // Move to next character after '-'
                _neg = true; // Set flag to true for negative number
            }

            v = digit(s[_i]); // Extract first digit

            // Extract remaining digits to form the number
            while (isDigit(s[++_i]))
                v = v * 10 + digit(s[_i]);

            // Negate the value if it was negative
            if (_neg)
                v = -v;

            // Do stuff with v (not specified in the provided code)

            // Update answer by taking maximum of current answer and sum
            ans = std::max(ans, sum < 0 ? sum = v : sum += v);
        }

        // Output the answer
        std::cout << ans;
    }

    // Exit after processing input
    exit(0);
    return 0;
}();

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curMax = 0, maxTillNow = INT_MIN;
        for (auto c : nums)
            curMax = (c + curMax * (curMax > 0)),
            maxTillNow = maxTillNow * (maxTillNow > curMax) + (maxTillNow > curMax) * curMax;
        return maxTillNow;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums;
    sol.maxSubArray(nums);
    return 0;
}
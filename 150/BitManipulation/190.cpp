// Reverse Bits

// https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i)
        {
            result <<= 1;      // Left shift result to make space for the next bit
            result |= (n & 1); // Extract the LSB of n and append it to result
            n >>= 1;           // Right shift n to process the next bit
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    uint32_t n = 43261596;

    Solution solution;
    cout << solution.reverseBits(n) << endl;
    return 0;
}
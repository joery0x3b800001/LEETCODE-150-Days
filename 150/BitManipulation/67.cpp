// Add Binary

// https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += (a[i--] - '0');
            if (j >= 0)
                sum += (b[j--] - '0');
            carry = sum / 2;
            result = to_string(sum % 2) + result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string a = "1010", b = "1011";

    Solution solution;
    cout << solution.addBinary(a, b) << endl;
    return 0;
}
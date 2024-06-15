// Majority Element
// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");

    for (string s; getline(cin, s); out << '\n') {
        int ans = 0;
        int c = 0;

        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;

            if (s[_i] == '-') {
                ++_i;
                _neg = true;
            }

            int v = s[_i++] & 15;

            while ((s[_i] & 15) < 10)
                v = v * 10 + (s[_i++] & 15);

            if (_neg)
                v = -v;

            if (c == 0)
                ans = v;
            
            ans == v ? ++c : --c;
        }
        out << ans;
    }
    out.flush();
    exit(0);
    return 0;
}();


class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int curr = 0;
        int count = 0;

        for (int num : nums)
        {
            if (count == 0)
                curr = num;

            if (curr == num)
                ++count;
            else
                --count;
        }

        return curr;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input
    int majority = sol.majorityElement(nums);

    cout << majority << endl;
    return 0;
}
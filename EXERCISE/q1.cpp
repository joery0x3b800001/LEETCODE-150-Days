#include <vector>
#include <iostream>
#include <set>

using namespace std;

// int index = 0;
//         if (nums.size()) {
//             int last = nums[index++];
//             for (int n : nums) {
//                 if (n != last)
//                     last = nums[index++] = n;
//             }
//         }
//         return index;

int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    int i;

    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }

    nums.clear();

    for (auto it : st)
    {
        nums.push_back(it);
    }
    return st.size();
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 2};

    cout << removeDuplicates(nums) << '\n';

    return 0;
}

// Array String

#include <bits/stdc++.h>

using namespace std;

// 88

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> result;

    for (int i = 0; i < m; i++)
    {
        result.push_back(nums1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        result.push_back(nums2[i]);
        sort(result.begin(), result.end());
        nums1 = result;
    }
}

// 27

int removeElement(vector<int> &nums, int val)
{
    vector<int> b;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != val)
        {
            b.push_back(nums[i]);
        }
        copy(b.begin(), b.end(), nums.begin());
        return b.size();
    }
}

// 26

int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    for (int num : nums)
    {
        st.insert(num);
    }

    copy(st.begin(), st.end(), nums.begin());

    return st.size();
}

// 80

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int j = 0;

    while (j < nums.size())
    {
        int temp = nums[j];
        int count = 0;

        while (j < nums.size() && temp == nums[j] && count < 2)
        {
            nums[i] = temp;
            i++;
            j++;
            count++;
        }

        while (j < nums.size() && temp == nums[j])
        {
            j++;
        }

        return i;
    }
}

// 169

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == candidate)
        {
            ++count;
        }
        else
        {
            --count;
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            ++count;
        }
    }

    return count > nums.size() / 2 ? candidate : -1;
}

// 189

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.end() + k);

    reverse(nums.begin() + k, nums.end());
}

// 121

int maxProfit(vector<int> &prices)
{
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

// 122

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}

// 55

bool canJump(vector<int> &nums)
{
    int lastPos = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        if (i + nums[i] >= lastPos)
        {
            lastPos = i;
        }
    }

    return lastPos == 0;
}

// 45

int jumps(vector<int> &nums)
{
    int jumps = 0;
    int curEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd)
        {
            curEnd = farthest;
            jumps++;
        }
    }

    return jumps;
}

// 274

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    int hIndex = 0;
    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] >= i + 1)
        {
            hIndex = i + 1;
        }
        else
        {
            break;
        }
    }

    return hIndex;
}

// 380

class RandomizedSet
{
private:
    unordered_map<int, int> map;
    vector<int> values;

public:
    RandomizedSet()
    {
        [=]
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
        }();
    }

    bool insert(int val)
    {
        if (map.find(val) != map.end())
        {
            return false;
        }
        values.push_back(val);
        map[val] = values.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end())
        {
            return true;
        }

        int index = map[val];
        values[index] = values.back();
        map[values.back()] = index;
        values.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        return values[rand() % values.size()];
    }
}

// 238

vector<int>
productExceptSelf(vector<int> &nums)
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

    // Compute Suffi Array
    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        output[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }

    return output;
}

// 134

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();

    int start = 0;
    int total_gas = 0;
    int tank = 0;

    for (int i = 0; i < n; ++i)
    {
        tank += gas[i] - cost[i];
        total_gas += gas[i] = cost[i];

        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }

        if (total_gas < 0)
            return -1;

        return start;
    }
}

// 135

int candy(vector<int> &ratings)
{
    vector<int> candies(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int j = ratings.size() - 2; i >= 0; i--)
    {
        if (ratings[j] > ratings[j + 1])
        {
            if (candies[j] <= candies[j + 1])
                candies[j] = candies[j + 1] + 1;
        }
    }

    int sum = accumulate(candies.begin(), candies.end(), 0);
    return sum;
}

// 42

int trap(vector<int>& height)
{
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int area = 0;

    while (left < right)
    {
        
    }
}
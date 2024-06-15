#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
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

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end() + k);

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
}

int maxProfit(vector<int> &prices)
{
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;

    for (int price : prices)
    {
        minPrice = min(price, minPrice);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

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

bool canJump(vector<int>& nums)
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

int jump(vector<int>& nums)
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

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    int hIndex = 0;
    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] >= i + 1)
        {
            hIndex = i + 1;
        } else {
            break;
        }
    }
    return hIndex;
}

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

vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();
    vector<int> output(n, 1);

    int prefixProduct = 1;
    for (int i = 0; i < n; ++i)
    {
        output[i] *= prefixProduct;
        prefixProduct *= nums[i];
    }

    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; --i){
        output[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
}

int main(int argc, char const *argv[]){
    
}
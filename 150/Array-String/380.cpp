// Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
private:
    std::unordered_map<int, int> map; // Map to store (value, index) pairs
    std::vector<int> values;          // Vector to store values

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        [=]()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
        }();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.find(val) != map.end())
        {
            return false; // Value already exists in the set
        }
        values.push_back(val);
        map[val] = values.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
        {
            return false; // Value doesn't exist in the set
        }
        int index = map[val];
        // Move the last element to the position of the element to be removed
        values[index] = values.back();
        map[values.back()] = index;
        values.pop_back();
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char const *argv[])
{
    vector<int> input = {1, 2, 2, 1, 2};

    RandomizedSet *obj = new RandomizedSet();
    bool param1 = obj->insert(input[0]);
    bool param2 = obj->remove(input[1]);
    bool param3 = obj->insert(input[2]);
    int param4 = obj->getRandom();
    bool param5 = obj->remove(input[3]);
    bool param6 = obj->insert(input[4]);
    int param7 = obj->getRandom();

    cout << param1 << " " << param2 << " " << param3 << " " << param4
         << " " << param5 << " " << param6 << " " << param7 << endl;
    return 0;
}
// Gas Station
// https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int start = 0; // start station
        int total_gas = 0;
        int tank = 0;

        for (int i = 0; i < n; ++i)
        {
            tank += gas[i] - cost[i];      // add gas from current station, subtract cost to next station
            total_gas += gas[i] - cost[i]; // track total gas - cost

            // if tank is negative, reset start station and tank.
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        // if total gas - cost is negative, it's impossible to complete the circuit
        if (total_gas < 0)
            return -1;

        return start;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int start = sol.canCompleteCircuit(gas, cost);
    if (start != -1)
    {
        cout << "Starting station index: " << start << endl;
    }
    else
    {
        cout << "It is impossible to complete the circuit." << endl;
    }

    return 0;
}
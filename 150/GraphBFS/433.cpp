// Minimum Genetic Mutation

// https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // Convert bank to unordered_set for O(1) lookup
        unordered_set<string> bankSet(bank.begin(), bank.end());

        // Check if end game is not in the bank
        if (bankSet.find(endGene) == bankSet.end())
        {
            return -1;
        }

        // Possible mutations
        vector<char> mutations = {'A', 'C', 'G', 'T'};

        // Queue for BFS
        queue<pair<string, int>> q;
        q.push({startGene, 0}); // Start with start gene and 0 mutations

        // Set to keep track of visited genes
        unordered_set<string> visited;
        visited.insert(startGene);

        while (!q.empty())
        {
            auto [gene, mutationSoFar] = q.front();
            q.pop();

            // If we returned the end gene, return the number of mutations
            if (gene == endGene)
            {
                return mutationSoFar;
            }

            // Try all possible mutations
            for (int i = 0; i < gene.size(); ++i)
            {
                char originalChar = gene[i];
                for (char mutation : mutations)
                {
                    gene[i] = mutation;
                    // Check if the mutated gene is in the bank and not visited yet
                    if (bankSet.find(gene) != bankSet.end() && visited.find(gene) == visited.end())
                    {
                        q.push({gene, mutationSoFar + 1});
                        visited.insert(gene);
                    }
                }
                // Revert the mutation for next iteration
                gene[i] = originalChar;
            }
        }

        // If no mutation sequence exists
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    Solution sol;
    cout << "Minimum number of mutations: " << sol.minMutation(start, end, bank) << endl;

    return 0;
}
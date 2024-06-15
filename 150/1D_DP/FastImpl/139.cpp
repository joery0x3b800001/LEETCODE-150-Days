// Word Break

// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    bool isComplete;
    TrieNode *children[26];

    TrieNode()
    {
        isComplete = 0;
        memset(children, 0, sizeof(children));
    }
};

class Trie
{
public:
    // Main root
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (auto ch : word)
        {
            int ind = ch - 'a';
            if (curr->children[ind] == NULL)
            {
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->isComplete = 1;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (auto ch : word)
        {
            int ind = ch - 'a';
            if (curr->children[ind] == NULL)
            {
                return 0;
            }
            curr = curr->children[ind];
        }
        return curr->isComplete == 1;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (auto ch : prefix)
        {
            int ind = ch - 'a';
            if (curr->children[ind] == NULL)
            {
                return 0;
            }
            curr = curr->children[ind];
        }
        return 1;
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie *node = new Trie();
        TrieNode *root = node->root;
        for (auto word : wordDict)
        {
            node->insert(word);
        }

        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || dp[i - 1] == 1)
            {
                TrieNode *curr = root;
                for (int j = i; j < n; j++)
                {
                    int ind = s[j] - 'a';
                    if (curr->children[ind] == NULL)
                        break;

                    curr = curr->children[ind];

                    if (curr->isComplete)
                    {
                        dp[j] = 1;
                    }
                }
            }
        }

        return dp[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    // Example usage
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution solution;
    bool canBreak = solution.wordBreak(s, wordDict);
    cout << "Can the string be segmented into words from the dictionary? " << (canBreak ? "Yes" : "No") << endl;
    return 0;
}
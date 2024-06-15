// Implement Trie (Prefix Tree)

// https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    bool isEnd;
    unordered_map<char, TrieNode *> children;

    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false; // Character not found
            }
            node = node->children[ch];
        }
        return node->isEnd; // Check if the word ends at this node
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            if (node->children.find(ch) == node->children.end())
            {
                return false; // Character not found
            }
            node = node->children[ch];
        }
        return true; // Prefix found
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[])
{
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // return True
    cout << trie->search("app") << endl;     // return False
    cout << trie->startsWith("app") << endl; // return True
    trie->insert("app");
    cout << trie->search("app") << endl; // return True
}
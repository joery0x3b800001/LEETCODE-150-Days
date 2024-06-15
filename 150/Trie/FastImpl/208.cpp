// Implement Trie (Prefix Tree)

// https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

static int init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    return 0;
}();

struct TrieNode
{
    TrieNode *nodes['z' - 'a' + 1];
    bool end = false;

    TrieNode()
    {
        for (int i = 0; i < std::size(nodes); ++i)
        {
            nodes[i] = nullptr;
        }
    }
};

class Trie
{
public:
    void insert(string word)
    {
        TrieNode *head = m_root;
        for (char c : word)
        {
            TrieNode *&node = head->nodes[c - 'a'];
            if (node == nullptr)
            {
                node = new TrieNode();
            }

            head = node;
        }

        head->end = true;
    }

    bool search(string word)
    {
        TrieNode *head = m_root;
        for (char c : word)
        {
            TrieNode *node = head->nodes[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }

            head = node;
        }

        return head->end;
    }

    bool startsWith(string prefix)
    {
        TrieNode *head = m_root;
        for (char c : prefix)
        {
            TrieNode *node = head->nodes[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }

            head = node;
        }

        return true;
    }

private:
    TrieNode *m_root = new TrieNode();
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
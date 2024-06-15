// Design Add and Search Words Data Structure

// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class WordDictionary
{
private:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        bool isEnd;

        TrieNode()
        {
            isEnd = false;
        }
    };

    TrieNode *root;

    // Recursive function to search word in Trie
    bool searchWord(TrieNode *node, const string &word, int index)
    {
        if (index == word.length())
        {
            return node->isEnd;
        }

        char c = word[index];
        if (c == '.')
        {
            for (auto &[ch, child] : node->children)
            {
                if (searchWord(child, word, index + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            if (!node->children.count(c))
            {
                return false;
            }
            return searchWord(node->children[c], word, index + 1);
        }
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children.count(c))
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        return searchWord(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char const *argv[])
{
    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    cout << wordDictionary->search("pad") << endl; // return False
    cout << wordDictionary->search("bad") << endl; // return True
    cout << wordDictionary->search(".ad") << endl; // return True
    cout << wordDictionary->search("b..") << endl; // return True
}
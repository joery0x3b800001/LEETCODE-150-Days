// Design Add and Search Words Data Structure

// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

static const int init = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class WordDictionary
{
private:
    int tree[260003][26] = {{0}};
    bool end[260003] = {0};
    int cnt = 1;
    bool count(int cur, const string &word, char c, int i, const int v)
    {
        while (c != '.')
        {
            cur = tree[cur][c - 'a'];
            if (cur == 0)
                return false;
            if (i >= v)
                return end[cur];
            c = word[i];
            i++;
        }
        for (c = 0; c < 26; ++c)
        {
            if (tree[cur][c] == 0)
                continue;
            if (i < v)
            {
                if (count(tree[cur][c], word, word[i], i + 1, v))
                    return true;
            }
            else
            {
                if (end[tree[cur][c]])
                    return true;
            }
            continue;
        }
        return false;
    }

public:
    WordDictionary() = default;
    const inline void addWord(const string &word)
    {
        const int n = word.size();
        int cur = 1;
        for (int i = 0; i < n; ++i)
        {
            const int path = word[i] - 'a';
            if (tree[cur][path] == 0)
                tree[cur][path] = ++cnt;
            cur = tree[cur][path];
        }
        end[cur] = true;
    }
    const inline bool search(const string &word)
    {
        return count(1, word, word[0], 1, word.size());
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
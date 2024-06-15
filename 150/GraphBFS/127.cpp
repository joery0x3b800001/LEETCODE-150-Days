// Word Ladder

// https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0; // End word is not in the word list
        }

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                string currentWord = q.front();
                q.pop();

                // Generate all possible one-letter mutation of currentWord
                for (int j = 0; j < currentWord.size(); ++j)
                {
                    char originalChar = currentWord[j];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == originalChar)
                        {
                            continue; // Skip same character
                        }
                        currentWord[j] = c;

                        // If we found the endWord, return the number of transformations
                        if (currentWord == endWord)
                        {
                            return level + 1;
                        }

                        // If the mutated word is in the word list, add it to the queue
                        if (wordSet.find(currentWord) != wordSet.end())
                        {
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Mark as visited
                        }
                    }
                    // Revert the change for the next mutation
                    currentWord[j] = originalChar;
                }
            }
            level++;
        }

        return 0; // No transformation sequence exists
    }
};

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution sol;
    cout << "Minimum transformation sequence length: " << sol.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
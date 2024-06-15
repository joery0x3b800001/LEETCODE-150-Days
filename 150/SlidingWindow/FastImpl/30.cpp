#include <bits/stdc++.h>
#include <string_view>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        vector<int> results;
        string left_word;
        int word_length = words[0].size();
        int total_length = words.size() * word_length;
        if (total_length > s.size())
            return results;
        unordered_map<string, int> words_count;
        for (auto word : words)
            words_count[word]++;

        for (int i = 0; i < word_length; i++)
        {
            int left = i;
            unordered_map<string, int> words_seen;
            for (int j = i; j <= s.size() - word_length; j += word_length)
            {
                string cur_word = s.substr(j, word_length);
                if (words_count.find(cur_word) == words_count.end())
                {
                    left = j + word_length;
                    if (left > s.size() - total_length)
                        break;
                    words_seen.clear();
                }
                else
                {
                    words_seen[cur_word]++;
                    while (words_seen[cur_word] > words_count[cur_word])
                    {
                        left_word = s.substr(left, word_length);
                        words_seen[left_word]--;
                        left += word_length;
                    }
                    if (j - left + word_length == total_length)
                    {
                        results.push_back(left);
                        left_word = s.substr(left, word_length);
                        words_seen[left_word]--;
                        left += word_length;
                    }
                }
            }
        }
        return results;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> result = sol.findSubstring(s, words);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
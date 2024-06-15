// Text Justification
// https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150

// https://stackoverflow.com/questions/62447529/how-do-i-reduce-the-running-time-of-the-code-to-justify-text

#include <bits/stdc++.h>

using namespace std;

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
{
    std::vector<std::string> res;
    std::vector<std::string> cur;
    int num_of_letters = 0;

    for (std::string word : words)
    {
        if (word.size() + cur.size() + num_of_letters > maxWidth)
        {
            for (int i = 0; i < maxWidth - num_of_letters; i++)
            {
                cur[i % (cur.size() - 1 ? cur.size() - 1 : 1)] += ' ';
            }
            res.push_back("");
            for (std::string s : cur)
                res.back() += s;
            cur.clear();
            num_of_letters = 0;
        }
        cur.push_back(word);
        num_of_letters += word.size();
    }

    std::string last_line = "";
    for (std::string s : cur)
        last_line += s + ' ';
    last_line = last_line.substr(0, last_line.size() - 1); // remove trailing space
    while (last_line.size() < maxWidth)
        last_line += ' ';
    res.push_back(last_line);

    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> words1 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth1 = 16;

    vector<string> words2 = {"Science", "is", "what", "we", "understand", "well", "enough", "to",
                             "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth2 = 20;

    auto result = fullJustify(words2, maxWidth2);

    for (auto t : result)
    {
        cout << t << endl;
    }

    return 0;
}
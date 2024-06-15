// Text Justification
// https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150

// https://stackoverflow.com/questions/62447529/how-do-i-reduce-the-running-time-of-the-code-to-justify-text

#include <bits/stdc++.h>

using namespace std;

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
{
    int st = 0;
    vector<string> ans;
    while (st < words.size())
    {
        int len = words[st].length();
        int spaces = 0;
        int tmp_st = st + 1;
        while (tmp_st < words.size())
        {
            if (len + 1 + words[tmp_st].length() <= maxWidth)
            {
                len += (1 + words[tmp_st].length());
                spaces++;
            }
            else
            {
                break;
            }
            tmp_st++;
        }
        string word = "";
        int extra_spaces = maxWidth - len;
        if (tmp_st == words.size())
        {
            extra_spaces = 0;
        }
        for (int j = st; j < tmp_st; j++)
        {
            word += words[j];
            if (j == (tmp_st - 1))
                break;
            word += " ";
            int div = extra_spaces / spaces;
            while (div > 0)
            {
                word += " ";
                div--;
            }
            if (extra_spaces % spaces != 0)
            {
                word += " ";
                extra_spaces--;
            }
        }
        while ((maxWidth - word.length()) > 0)
        {
            word += " ";
        }
        ans.push_back(word);
        // cout << "word" << endl;
        st = tmp_st;
    }
    return ans;
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

    auto result = fullJustify(words1, maxWidth1);

    for (auto t : result)
    {
        cout << t << endl;
    }

    return 0;
}
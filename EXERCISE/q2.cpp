#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void util(string s, int idx, int dot, string str, vector<string> &ans)
{
    if (dot > 4)
        return;

    if (idx == s.length())
    {
        if (dot == 4)
            ans.push_back(str.substr(0, str.size() - 1));
        return;
    }

    for (int j = idx; j < min(idx + 3, (int)s.size()); j++)
    {
        if (stoi(s.substr(idx, j - idx + 1)) < 256 && (idx == j || s[idx] != '0'))
            util(s, j + 1, dot + 1, str + s.substr(idx, j - idx + 1) + ".", ans);
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    if (s.length() > 12)
        return ans;
    util(s, 0, 0, "", ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> res;
    string s;

    cin >> s;
    res = restoreIpAddresses(s);

    for (auto x : res)
    {
        cout << x << '\n';
    }
    return 0;
}

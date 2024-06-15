// Simplify Path

// https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        std::vector<std::string> dirs;
        int start = 0;
        int end = 0;

        while (start < path.size())
        {
            // Find the start of the next directory name
            while (start < path.size() && path[start] == '/')
            {
                start++;
            }

            // Find the end of the current directory name
            end = start;
            while (end < path.size() && path[end] != '/')
            {
                end++;
            }

            // Extract the current directory name
            std::string dir = path.substr(start, end - start);

            // Process the current directory name
            if (dir == "..")
            {
                if (!dirs.empty())
                {
                    dirs.pop_back();
                }
            }
            else if (dir != "." && !dir.empty())
            {
                dirs.push_back(dir);
            }

            start = end;
        }

        // Construct the simplified path
        std::string simplifiedPath;
        for (const std::string &dir : dirs)
        {
            simplifiedPath += "/" + dir;
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string path = "/home/user/Documents/../Pictures";
    cout << sol.simplifyPath(path) << endl;
    return 0;
}
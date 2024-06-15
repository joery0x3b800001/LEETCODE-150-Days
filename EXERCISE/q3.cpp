#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int candy(vector<int> &ratings)
{
    vector<int> candies(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int j = ratings.size() - 2; j >= 0; j--)
    {
        if (ratings[j] > ratings[j + 1])
        {
            if (candies[j] <= candies[j + 1])
                candies[j] = candies[j + 1] + 1;
        }
    }

    int sum = accumulate(candies.begin(), candies.end(), 0);
    return sum;
}

int main(int argc, char const *argv[])
{

    vector<int> ratings = {1, 0, 2};

    cout << candy(ratings) << '\n';
    return 0;
}

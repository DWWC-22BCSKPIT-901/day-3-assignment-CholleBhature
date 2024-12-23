#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n, 1);

    // Left to right pass
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Calculate the total number of candies
    int totalCandies = 0;
    for (int candy : candies)
    {
        totalCandies += candy;
    }

    return totalCandies;
}

int main()
{
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies required: " << candy(ratings) << endl;

    ratings = {1, 2, 2};
    cout << "Minimum candies required: " << candy(ratings) << endl;

    return 0;
}
//There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
//You are giving candies to these children subjected to the following requirements : Each child must have at least one candy.Children with a higher rating get more candies than their neighbors.Return the minimum number of candies you need to have to distribute the candies to the children.in cpp
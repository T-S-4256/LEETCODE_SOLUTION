#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long totalCandies = 0;
        int first = 0;
        long last = candies.size() - 1;
        long maxPile = 0;
        // total candies count
        while (first <= last)
        {
            long maxCand = max(candies[first], candies[last]);
            maxPile = max(maxPile, maxCand);
            totalCandies += candies[first];
            totalCandies += candies[last];
            first++;
            last--;
        }

        // agar candies hi kam ho total child se tab?
        if (totalCandies < k)
        {
            return 0;
        }

        first = 1;
        last = maxPile;
        long mid;
        long result = 0;
        while (first <= last)
        {
            mid = (first + last) / 2;
            long long child = 0;
            for (int i = 0; i < candies.size(); i++)
            {
                if (candies[i] >= mid)
                {
                    child += (candies[i] / mid);
                }
                if (child >= k)
                {
                    result = mid;
                    first = mid + 1;
                    break;
                }
            }
            if (child < k)
            {
                last = mid - 1;
                child = 0;
            }
            else
            {
                child = 0;
            }
        }
        return result;
    }
};

int main()
{

    // Input: candies = [5,8,6], k = 3
    // Output: 5

    // Input: candies = [2,5], k = 11
    // Output: 0

    // Input: candies = [4,7,5], k = 4
    // Output: 3

    vector<int> candies = {4,7,5};

    Solution s;
    cout << s.maximumCandies(candies, 4);
    return 0;
}
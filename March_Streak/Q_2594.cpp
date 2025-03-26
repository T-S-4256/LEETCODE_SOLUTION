#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &ranks, long long mid, int cars)
    {
        long long result = 0;
        for (int i = 0; i < ranks.size(); i++)
        {
            long long num = floor(mid / ranks[i]);
            result += floor(sqrt(num));
        }
        return result >= cars;
    }

    long long repairCars(vector<int> &ranks, int cars)
    {
        long long l = 0;
        long long  r =LONG_LONG_MAX;
        long long result = -1;
        long long mid;
        while (l <= r)
        {

            mid = (l + r) / 2;
            mid = floor(mid);
            if (isPossible(ranks, mid, cars))
            {
                result = mid;
                r = mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: ranks = [4,2,3,1], cars = 10
    // Output: 16
    // CASE 2:
    // Input: ranks = [5,1,8], cars = 6
    // Output: 16
    // CASE 3:
    // [31,31,5,19,19,10,31,18,19,3,16,20,4,16,2,25,10,16,23,18,21,23,28,6,7,29,11,11,19,20,24,19,26,12,29,29,1,14,17,26,24,7,11,28,22,14,31,12,3,19,16,26,11]
    // cars :736185
    // o/p : 2358388332
    Solution s;
    vector<int> rank = {31,31,5,19,19,10,31,18,19,3,16,20,4,16,2,25,10,16,23,18,21,23,28,6,7,29,11,11,19,20,24,19,26,12,29,29,1,14,17,26,24,7,11,28,22,14,31,12,3,19,16,26,11};
    cout << s.repairCars(rank, 736185);

    return 0;
}
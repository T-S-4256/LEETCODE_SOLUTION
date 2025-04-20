#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long bruthForceApproach(vector<int> &nums, int lower, int upper)
    {
        long long result = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (lower <= (nums[i] + nums[j]) && (nums[i] + nums[j]) >= upper)
                {
                    result++;
                }
            }
        }
        return result;
    }
    // long long countFairPairs(vector<int> &nums, int lower, int upper)
    // {
    //     int  n=nums.size();
    //     int i=0;
    //     int j=i+1;
    //     int result=0;
    //     while(j<n){
    //         if (lower<=(nums[i]+nums[j])&&(nums[i]+nums[j])<=upper){
    //             result++;
    //         }
    //         j++;
    //     }
    // }
};

int main()
{
    // CASE 1:
    // Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    // Output: 6
    // CASE 2:
    // Input: nums = [1,7,9,2,5], lower = 11, upper = 11
    // Output: 1

    return 0;
}
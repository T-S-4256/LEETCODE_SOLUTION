#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long maxi = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            long long result = 0;
            for (int j = i+1; j < nums.size() - 1; j++)
            {
                for (int k = j+1; k < nums.size(); k++)
                {
                    result = (long long)(nums[i] - nums[j]) * nums[k];
                    if (maxi < result)
                    {
                        maxi = result;
                    }
                }
            }
        }

        return maxi > 0 ? maxi : 0;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = {12,6,1,2,7}
    // Output: 77
    // CASE 2:
    // Input: nums = {1,10,3,4,19}
    // Output: 133
    // CASE 3:
    // Input: nums = {1,2,3}
    // Output: 0
    // CASE 4:
    // input : nums={10,13,6,2}
    // output:14

    Solution s;
    // vector<int> nums = {12, 6, 1, 2, 7};
    vector<int> nums = {10,13,6,2};
    cout << s.maximumTripletValue(nums);

    return 0;
}
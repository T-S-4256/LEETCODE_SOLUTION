#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int lastIndex = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     mp[nums[i]] = i + 1;
        // }
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] != 0)
            {
                if (lastIndex < mp[nums[i]])
                {
                    lastIndex = mp[nums[i]];
                    mp[nums[i]] = i + 1;
                }
                else
                {
                    mp[nums[i]] = i + 1;
                }
            }
            else
            {
                mp[nums[i]] = i + 1;
            }
        }
        return ceil(float(lastIndex / 3));
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [1,2,3,4,2,3,3,5,7]
    // Output: 2
    // CASE 2:
    // Input: nums = [4,5,6,4,4]
    // Output: 2
    // CASE 3:
    // Input: nums = [6,7,8,9]
    // Output: 0
    // [14,3,14,15,15,11,14,13,14]
    // 3

    Solution s;
    vector<int> nums = {14, 3, 14, 15, 15, 11, 14, 13, 14};
    cout << "Ans : " << s.minimumOperations(nums);

    return 0;
}
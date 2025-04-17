#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // int i = 0, j = 0;
        // int result=0;
        // while (j < n)
        // {
        //     if(mp[nums[j]]==1){
        //         if()
        //     }
        // }
        int result = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    if ((i * j) % k == 0)
                    {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [3,1,2,2,2,1,3], k = 2
    // Output: 4
    // CASE 2:
    // Input: nums = [1,2,3,4], k = 1
    // Output: 0
    Solution s;
    // vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    vector<int> nums = {1,2,3,4};
    cout<<"Ans : "<<s.countPairs(nums,1);
    return 0;
}
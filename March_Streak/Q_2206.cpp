#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        // int result = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     result ^= nums[i];
        // }
        // cout<<result<<endl;
        // return (!result);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto i : mp)
        {
            if (i.second % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [3,2,3,2,2,2]
    // Output: true
    // CASE 2:
    // Input: nums = [1,2,3,4]
    // Output: false
    // CASE 3:
    // Input: nums =[9,9,19,10,9,12,2,12,3,3,11,5,8,4,13,6,2,11,9,19,11,15,9,17,15,12,5,14,12,16,18,16,10,3,8,9,16,20,2,4,16,12,11,14,20,16,2,18,17,20,3,13,16,17,1,1,11,20,20,4]
    // Output: false

    Solution s;
    vector<int> nums = {3,2,3,2,2,2};
    cout << "Ans Is : " << s.divideArray(nums);

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        long long pairs=0;
        int n=nums.size();
        int i = 0;
        int j = 0;
        long long result = 0;
        while (j < n)
        {
            pairs+=mp[nums[j]];
            mp[nums[j]]++;
            while(pairs>=k){
                result+=(n-j);
                mp[nums[i]]--;
                pairs-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [1,1,1,1,1], k = 10
    // Output: 1
    // CASE 2:
    // Input: nums = [3,1,4,3,2,2,4], k = 2
    // Output: 4
    Solution s1;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << "Ans : " << s1.countGood(nums, 10);
    return 0;
}
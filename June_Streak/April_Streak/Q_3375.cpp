#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        unordered_set<int> uniqueVal;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < k)
            {
                return -1;
            }
            if (nums[i] > k)
            {
                uniqueVal.insert(nums[i]);
            }
        }
        return uniqueVal.size();
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [5,2,5,4,5], k = 2
    // Output: 2
    // CASE 2:
    // Input: nums = [2,1,2], k = 2
    // Output: -1
    // CASE 3:
    // Input: nums = [9,7,5,3], k = 1
    // Output: 4

    Solution s;
    vector<int> nums = {5, 2, 5, 4, 5};
    // vector<int> nums={2,1,2};
    // vector<int> nums={9,7,5,3};
    cout << "Ans : " << s.minOperations(nums, 2);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == (2 * (nums[i - 1] + nums[i + 1])))
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [1,1,1]
    // Output: 0
    // CASE 2:
    // Input: nums = [1,2,1,4,1]
    // Output: 1

    Solution s;
    vector<int> nums = {1, 2, 1, 4, 1};
    cout << "Ans  : " << s.countSubarrays(nums);

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int digits = int(log10(nums[i])) + 1;
            if (digits % 2 == 0)
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
    // Input: nums = [12,345,2,6,7896]
    // Output: 2
    // CASE 2:
    // Input: nums = [555,901,482,1771]
    // Output: 1

    Solution s;
    vector<int> nums = {555,901,482,1771};
    cout << "total Number Of Even Digit Numbers Are : " << s.findNumbers(nums);

    return 0;
}
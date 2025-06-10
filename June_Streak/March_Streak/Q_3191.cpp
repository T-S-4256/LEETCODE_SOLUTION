#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void print_karo(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " : ";
        }
        cout << endl;
    }
    int minOperations(vector<int> &nums)
    {
        if (nums.size() == 3)
        {
            if (nums[0] == 1 && nums[1] == 1 && nums[2] == 1)
            {
                return 0;
            }
            else if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
            {
                return 1;
            }
            return -1;
        }
        int count = 0;
        for (int i = 0; i <= nums.size() - 3; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = !(nums[i]);
                nums[i + 1] = !(nums[i + 1]);
                nums[i + 2] = !(nums[i + 2]);
                count++;
            }
            print_karo(nums);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                return -1;
            }
        }
        return count;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [0,1,1,1,0,0]
    // Output: 3
    // CASE 2:
    // Input: nums = [0,1,1,1]
    // Output: -1
    // CASE 3:
    // Input: nums=[1,1,1,1,1,1,1,0]
    // Output:-1

    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 0};
    cout << "Ans : " << s.minOperations(nums);
    return 0;
}
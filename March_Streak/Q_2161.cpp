#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                less.push_back(nums[i]);
            }
            else if (nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
            else
            {
                greater.push_back(nums[i]);
            }
        }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == pivot)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > pivot)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        // }
        less.insert(less.end(),equal.begin(),equal.end());
        less.insert(less.end(),greater.begin(),greater.end());
        return less;
    }
};

int main()
{
    //     CASE 1
    //     Input: nums = [9,12,5,10,14,3,10], pivot = 10
    // Output: [9,5,3,10,10,12,14]

    // CASE 2
    // Input: nums = [-3,4,3,2], pivot = 2
    // Output: [-3,2,4,3]

    Solution s;
    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    vector<int> ans;
    ans = s.pivotArray(nums, 10);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " : ";
    }
    cout << endl;
    cout << "Expacted Output Is : 9,5,3,10,10,12,14";
    return 0;
}
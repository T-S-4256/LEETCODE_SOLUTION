#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> result;

    void solve(vector<int> &nums, int index, vector<int> &temp)
    {
        if (index >= nums.size())
        {
            if (!temp.empty())
            {
                int ans = temp[0];
                for (int i = 1; i < temp.size(); i++)
                {
                    ans ^= temp[i];
                }
                result.push_back(ans);
            }
            return;
        }

        // TAKE THE CURRENT ELEMENT
        temp.push_back(nums[index]);
        solve(nums, index + 1, temp);

        // NOT TAKE THE CURRENT ELEMENT
        temp.pop_back();
        solve(nums, index + 1, temp);
    }
    int subsetXORSum(vector<int> &nums)
    {

        // FINDING ALL THE SUBSET
        vector<int> temp;
        solve(nums, 0, temp);

        // ADD ALL THE SUBSET XOR
        int ans = 0;
        for (int i = 0; i < result.size(); i++)
        {
            ans += result[i];
        }

        // PRINTING ALL THE SUBARRAY 
        
        // for (int i = 0; i < result.size(); i++)
        // {
        //     for (int j = 0; j < result[i].size(); j++)
        //     {
        //         cout << result[i][j] << " : ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [1,3]
    // Output: 6
    // CASE 2:
    // Input: nums = [5,1,6]
    // Output: 28
    // CASE 3:
    // Input: nums = [3,4,5,6,7,8]
    // Output: 480

    Solution s;
    vector<int> num = {5, 1, 6};
    cout << "Ans : " << s.subsetXORSum(num);

    return 0;
}

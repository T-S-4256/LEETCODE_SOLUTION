#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void printKaro(vector<int> nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " : ";
        }
        cout << endl;
    }
    long long maximumTripletValue(vector<int> &nums)
    {
        // int n3 = nums.size() - 1;

        // for (int i = n3 - 1; i >= 2; i--)
        // {
        //     if (nums[i] > nums[n3])
        //     {
        //         n3 = i;
        //     }
        // }

        // cout << "Num3 : " << nums[n3] << endl;
        // int n2 = n3 - 1;

        // for (int i = n2 - 1; i >= 1; i--)
        // {
        //     if (nums[i] < nums[n2])
        //     {
        //         n2 = i;
        //     }
        // }

        // cout << "Num2 : " << nums[n2] << endl;
        // int n1 = n2 - 1;

        // for (int i = n2 - 1; i >= 0; i--)
        // {
        //     if (nums[i] > nums[n1])
        //     {
        //         n1 = i;
        //     }
        // }
        // cout << "Num1 : " << nums[n1] << endl;
        // long long result = (long long)(nums[n1] - nums[n2]) * nums[n3];
        // cout << "Result : " << result << endl;
        // return result >= 0 ? result : 0;

        vector<int> leftMaxi(nums.size());
        vector<int> rightMaxi(nums.size());
        // printKaro(leftMaxi);
        for (int i = 1; i < nums.size(); i++)
        {
            leftMaxi[i] = max(leftMaxi[i - 1], nums[i - 1]);
        }
        // printKaro(leftMaxi);
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            rightMaxi[i] = max(rightMaxi[i + 1], nums[i + 1]);
        }
        // printKaro(rightMaxi);
        long long result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            result = max(result, (long long)((leftMaxi[i] - nums[i]) * rightMaxi[i]));
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = {12,6,1,2,7}
    // Output: 77
    // CASE 2:
    // Input: nums = {1,10,3,4,19}
    // Output: 133
    // CASE 3:
    // Input: nums = {1,2,3}
    // Output: 0
    // CASE 4:
    // input : {2,3,1}
    // output :0
    // CASE 5:
    // {8,6,3,13,2,12,19,5,19,6,10,11,9}
    // 266

    Solution s;
    // vector<int> nums = {1, 10, 3, 4, 19};
    // vector<int> nums = {2, 3, 1};
    vector<int> nums = {8, 6, 3, 13, 2, 12, 19, 5, 19, 6, 10, 11, 9};
    cout << s.maximumTripletValue(nums);

    return 0;
}
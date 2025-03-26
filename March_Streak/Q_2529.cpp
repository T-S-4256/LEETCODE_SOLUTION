#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int optimized_code(vector<int> &nums)
    {
        int pos = 0;
        int nag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                pos = nums.size() - i;
                break;
            }
            else if (nums[i] < 0)
            {
                nag++;
            }
        }
        return max(pos, nag);
    }

    int maximumCount(vector<int> &nums)
    {
        int pos = 0;
        int nag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                pos++;
            }
            else if (nums[i] < 0)
            {
                nag++;
            }
        }
        return max(pos, nag);
    }
};

int main()
{

    // CASE 2:
    // Input: nums = [-2,-1,-1,1,2,3]
    // Output: 3

    // CASE 2:
    // Input: nums = [-3,-2,-1,0,0,1,2]
    // Output: 3

    // CASE 3:
    // Input: nums = [5,20,66,1314]
    // Output: 4

    Solution s;
    vector<int> num = {-2,-1,-1,1,2,3};

    cout << "Ans Is : " << s.maximumCount(num)<<endl;
    cout << "Optimized Code Ans Is : " << s.optimized_code(num);

    return 0;
}
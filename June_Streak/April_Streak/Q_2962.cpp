#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxE = *max_element(begin(nums), end(nums));

        int n = nums.size();
        int i = 0, j = 0;

        long long result = 0;
        int countMax = 0;

        while (j < n)
        {
            if (nums[j] == maxE)
            {
                countMax++;
            }

            while (countMax >= k)
            {
                result += n - j;

                if (nums[i] == maxE)
                {
                    countMax--;
                }
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
    // Input: nums = [1,3,2,3,3], k = 2
    // Output: 6
    // CASE 2:
    // Input: nums = [1,4,2,1], k = 3
    // Output: 0

    Solution s;
    vector<int> nums = {1, 3, 2, 3, 3};
    cout << "Total Subarray : " << s.countSubarrays(nums, 2);

    return 0;
}
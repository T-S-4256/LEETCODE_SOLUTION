#include <iostream>
#include <vector>
#include<algorithm>
#include <limits.h>
using namespace std;

// great question hard to understand
class Solution
{
public:
    int solve(vector<int> &nums, int i, int k, vector<vector<int>> &t)
    {
        int n = nums.size();
        if (k == 0)
        {
            cout << "K 0 Ho Gya Hai" << endl;
            return 0;
        }
        if (i >= n)
        {
            cout << "K 1 Ho Gya Hai" << endl;
            return INT_MAX;
        }
        if (t[i][k] != -1)
        {
            return t[i][k];
        }

        int take = max(nums[i], solve(nums, i + 2, k - 1, t));

        int not_take = max(nums[i], solve(nums, i + 1, k, t));
        cout << "Take : " << take << " Not_Take : " << not_take << " Min : " << min(take, not_take) << endl;
        return t[i][k] = min(take, not_take);
    }

    int normal_code(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1, -1));
        return solve(nums, 0, k, t);
    }
    // optimides code

    bool isPossible(vector<int> nums, int mid, int k)
    {
        int house = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                house++;
                i++;
            }
        }
        return house >= k;
    }

    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int result = r;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k) == true)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [2,3,5,9], k = 2
    // Output: 5

    // CASE 2:
    // Input: nums = [2,7,9,3,1], k = 2
    // Output: 2

    Solution s;
    vector<int> nums = {2, 3, 5, 9};

    cout << s.minCapability(nums, 2)<<endl;
    cout << s.normal_code(nums, 2);
    return 0;
}
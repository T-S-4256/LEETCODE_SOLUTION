#include <iostream>
#include<cstring>
#include<numeric>
#include <vector>
using namespace std;

class Solution {
    public:
        int t[201][20001];
        bool solve(vector<int>& nums, int i, int x) {
            if (x == 0) {
                return true;
            }
    
            if (i >= nums.size()) {
                return false;
            }
    
            if (t[i][x] != -1) {
                return t[i][x];
            }
    
            bool take = false;
            if (nums[i] <= x) {
                take = solve(nums, i + 1, x - nums[i]);
            }
    
            bool not_take = solve(nums, i + 1, x);
    
            return t[i][x] = take || not_take;
        }
    
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
    
            int S = accumulate(begin(nums), end(nums), 0);
    
            if (S % 2 != 0) {
                return false;
            }
            memset(t, -1, sizeof(t));        int x = S / 2;
    
            return solve(nums, 0, x);
        }
    };

int main()
{

    // CASE 1:
    // Input: nums = [1,5,11,5]
    // Output: true
    // CASE 2:
    // Input: nums = [1,2,3,5]
    // Output: false
    // CASE 3:
    // [2,2,3,5]
    Solution p;
    vector<int> nums = {1, 5, 11, 5};
    cout<<"Ans : ";
    return 0;
}
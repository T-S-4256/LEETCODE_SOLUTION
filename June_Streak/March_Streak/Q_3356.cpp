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

    bool check_all_element_zero(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool check_possiblity(vector<int> nums, vector<vector<int>> quaries, int mid)
    {
        vector<int> diff(nums.size(), 0);
        for (int i = 0; i <= mid; i++)
        {
            diff[quaries[i][0]] += quaries[i][2];
            if ((quaries[i][1] + 1) < nums.size())
            {
                diff[quaries[i][1] + 1] -= quaries[i][2];
            }
        }
        print_karo(diff);
        int comSum = 0;
        ;
        for (int i = 0; i < diff.size(); i++)
        {
            comSum += diff[i];
            diff[i] = comSum;

            if (nums[i] > diff[i])
            {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        if (check_all_element_zero(nums))
        {
            return 0;
        }
        int result = -1;
        int f = 0;
        int l = queries.size()-1;
        int mid;
        while (f <= l)
        {
            mid = (f + l) / 2;
            cout<<"MID : "<<mid<<" : ";
            if (check_possiblity(nums, queries, mid) == true)
            {
                cout<<"Chal Gya"<<endl;
                result = mid + 1;
                l = mid - 1;
            }
            else
            {
                cout<<"Nahi Chala"<<endl;
                f = mid + 1;
            }
        }

        return result;
    }
};

int main()
{

    // CASE 1:
    // Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
    // Output: -1

    // CASE 2:
    // Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
    // Output: 2

    // CASE 3:
    // INPUT :[7],QUEARIES:{[0,0,4],[0,0,1],[0,0,4],[0,0,4],[0,0,4],[0,0,4],[0,0,1],[0,0,5],[0,0,1],[0,0,3],[0,0,5],[0,0,2],[0,0,3],[0,0,1],[0,0,5]}
    // OUTPUT:3
    Solution s;
    vector<int> num = {7};
    vector<vector<int>> quearies = {{0,0,4}, {0,0,1}, {0,0,4},{0,0,4},{0,0,4},{0,0,4},{0,0,1},{0,0,5},{0,0,1},{0,0,3},{0,0,5},{0,0,2},{0,0,3},{0,0,1},{0,0,5}};

    cout << s.minZeroArray(num, quearies);

    return 0;
}
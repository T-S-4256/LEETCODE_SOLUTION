#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int num : nums)
        {
            mp2[num]++;
        }
        
        for (int i = 0; i < n; i++)
        {
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            int n1 = i + 1;
            int n2 = n - i - 1;

            if (mp1[nums[i]] > n1 / 2 && mp2[nums[i]] > n2 / 2)
            {
                return i;
            }
        }

        return -1;
    }
    int ordinaryWrongThink(vector<int> &nums)
    {
        // FIND THR DOMINANT ELEMENT IN THE VECTOR
        unordered_map<int, vector<int>> storage;
        int dominant = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            storage[nums[i]].push_back(i);
            int size = storage[nums[i]].size();
            if (size > dominant)
            {
                dominant = nums[i];
            }
        }

        // PRINTING THE DOMINANT DATA
        cout << "Dominant Is : " << dominant << endl;

        // PRINTING THE STORAGE DATA TO VERIFY
        // cout << "The Storage Value Are :" << endl;
        // for (auto &vec : storage)
        // {
        //     cout << "First : " << vec.first << " Second : " << " ";
        //     for (int i = 0; i < vec.second.size(); i++)
        //     {
        //         cout << vec.second[i] << " ";
        //     }
        //     cout << endl;
        // }

        // cout<<storage[dominant].size()<<endl;
        int count = 1;
        for (int i = 0; i < storage[dominant].size(); i++)
        {
            int part1Size = storage[dominant][i] + 1;
            int part2Size = (nums.size() - part1Size);
            cout << "Size : " << part1Size << " : " << part2Size << " ";
            part2Size /= 2;
            part1Size /= 2;
            cout << "Half : " << part1Size << " " << part2Size << " Count : " << count << endl;
            if (part1Size < count && part2Size < count)
            {
                return storage[dominant][i];
            }
            count++;
        }

        return -1;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [1,2,2,2]
    // Output: 2
    // CASE 2:
    // Input: nums = [2,1,3,1,1,1,7,1,2,1]
    // Output: 4
    // CASE 3:
    // Input: nums = [3,3,3,3,7,2,2]
    // Output: -1

    Solution s;
    // vector<int> nums = {1,2,2,2};
    // vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    vector<int> nums = {3, 3, 3, 3, 7, 2, 2};

    cout << "Ans : " << s.minimumIndex(nums);

    return 0;
}
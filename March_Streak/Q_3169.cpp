#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void print_karo(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    int optimised(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int result = 0;
        int first = meetings[0][0] - 1;
        int last = meetings[0][1] - 1;
        if ((first + 1) > 1)
        {
            result = first;
        }
        cout << "First : " << first << " Last : " << last << " Result : " << result << " : ";
        for (int i = 1; i < meetings.size(); i++)
        {
            if (meetings[i][0] - 1 <= last + 1)
            {
                first = meetings[i][0] - 1;
            }
            else
            {
                result = result + (meetings[i][0] - 1 - last - 1);
                first = meetings[i][0] - 1;
            }
            if (meetings[i][1] - 1 > last)
            {
                last = meetings[i][1] - 1;
            }
            cout << "First : " << first << " Last : " << last << " Result : " << result << " : ";
        }
        cout << endl;
        if (last < (days - 1))
        {
            result = result + ((days - 1) - last);
        }
        return result;
    }
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<int> ans(days, 0);
        int result = 0;
        for (int i = 0; i < meetings.size(); i++)
        {
            for (int j = meetings[i][0] - 1; j < meetings[i][1]; j++)
            {
                if (ans[j] == 0)
                {
                    ans[j] = -1;
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "ans[i] : " << ans[i] << " : ";
            if (ans[i] == 0)
            {
                result++;
            }
        }
        cout << endl;
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
    // Output: 2
    // CASE 2:
    // Input: days = 5, meetings = [[2,4],[1,3]]
    // Output: 1
    // CASE 3:
    // Input: days = 6, meetings = [[1,6]]
    // Output: 0
    Solution s;
    vector<vector<int>> meeting = {{5, 7}, {1, 3}, {9, 10}};
    // vector<vector<int>> meeting = {{6,11},{7,13},{8,9},{5,8},{3,13},{11,13},{1,3},{5,10},{8,13},{3,9}};
    // vector<vector<int>> meeting = {{2, 4}, {1, 3}};
    // cout << s.countDays(5, meeting);
    cout << s.optimised(10, meeting);

    return 0;
}
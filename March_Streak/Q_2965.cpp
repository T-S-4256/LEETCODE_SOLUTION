#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> ans(2);
        vector<int> flag(grid[0].size() * grid.size(), 0);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                flag[(grid[i][j] - 1)]++;
            }
        }

        for (int i = 0; i < flag.size(); i++)
        {
            if (flag[i] == 0)
            {
                ans[1] = i+1;
            }
            else if (flag[i] > 1)
            {
                ans[0] = i+1;
            }
        }

        return ans;
    }
};

int main()
{

    // CASE1:
    // Input: grid = [[1,3],[2,2]]
    // Output: [2,4]

    // CASE 2:
    // Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
    // Output: [9,5]
    vector<vector<int>> num = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans;
    Solution s;
    ans = s.findMissingAndRepeatedValues(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " : ";
    }

    return 0;
}
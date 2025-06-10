#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int result = 0;
        vector<int> storage;
        // CREATE A NEW CONTAINER TO STORE THE GRID ITEMS FOR SORTING
        int flag = 0;
        int counter = -1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (flag == 0 && grid[i][j] < counter)
                {
                    flag = 1;
                }
                if (flag == 0)
                {
                    counter = grid[i][j];
                }
                storage.push_back(grid[i][j]);
            }
        }
        if (storage.size() < 2)
        {
            return 0;
        }

        // SORT THE CONTAINER ELEMENTS
        if (flag == 1)
        {
            sort(storage.begin(), storage.end());
        }

        int midValue = floor(storage.size() / 2);

        // NOW CALCULATE THE MINIMUM OPERATION IS POSSIBLE
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i] % x != storage[midValue] % x)
            {
                return -1;
            }
            int ans = abs((storage[i] - storage[midValue]) / x);
            result += ans;
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: grid = {{2,4},{6,8}}, x = 2
    // Output: 4
    // CASE 2:
    // Input: grid = {{1,5},{2,3}}, x = 1
    // Output: 5
    // CASE 3:
    // Input: grid = {{1,2},{3,4}}, x = 2
    // Output: -1
    // CASE 4:
    // Input: grid = {{931,128},{639,712}}, x = 73
    // Output: 12

    Solution s;
    // vector<vector<int>> grid = {{2, 4}, {6, 8}};
    // vector<vector<int>> grid = {{1,5},{2,3}};
    vector<vector<int>> grid = {{931, 128}, {639, 712}};
    // vector<vector<int>> grid = {{1, 2}, {3, 4}};
    cout << s.minOperations(grid, 73);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int minVal = 0, maxVal = 0, curr = 0;
        for (int i = 0; i < differences.size(); i++)
        {
            curr = curr + differences[i];
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
            if ((upper - maxVal) - (lower - minVal) + 1 <= 0)
            {
                return 0;
            }
        }
        curr = (upper - maxVal) - (lower - minVal) + 1;
        return curr;
    }
};

int main()
{
    // CASE 1:
    // Input: differences = [1,-3,4], lower = 1, upper = 6
    // Output: 2
    // CASE 2:
    // Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
    // Output: 4
    // CASE 3:
    // Input: differences = [4,-7,2], lower = 3, upper = 6
    // Output: 0
    Solution s;
    vector<int> differences = {1, -3, 4};
    cout << "Ans  : " << s.numberOfArrays(differences, 1, 6);
    return 0;
}
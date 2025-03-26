#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int moreOptimized(string blocks, int k)
    {
        int len = blocks.length();
        int count = 0;
        int minCount = k;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
            {
                count++;
            }
        }
        minCount=count;
        for (int i = k; i < len; i++)
        {
            if (blocks[i] == 'W')
                count++;
            if (blocks[i - k] == 'W')
                count--;
            minCount = min(minCount, count);
        }

        return minCount;
    }
};
int main()
{
    // CASE 1:
    // Input: blocks = "WBBWWBBWBW", k = 7
    // Output: 3

    // CASE 2:
    // Input: blocks = "WBWBBBW", k = 2
    // Output: 0

    // CASE 3:
    // Input: blocks = "BWWWBB", k = 6
    // Output: 0

    // CASE 4:
    // Input: blocks = "WBWW", k = 2
    // Output: 0
    Solution s;
    string str = "WBWW";
    int k = 2;
    cout << "Sliding Window Approach :- Ans Is : " << s.moreOptimized(str, k);

    return 0;
}
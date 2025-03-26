#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void printKaro(vector<int> ans)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " : ";
        }
        cout << endl;
    }

    vector<int> applyOperations(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                if ((i + 1) < nums.size())
                {
                    nums[i + 1] = 0;
                }
            }
            printKaro(nums);
        }

        vector<int> result(nums.size(), 0);
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                result[count] = nums[i];
                count++;
            }
        }
        return result;
    }
};

int main()
{

    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> ans;

    Solution s;
    ans = s.applyOperations(nums);

    s.printKaro(ans);
    cout << "Expected Output IS : 1,4,2,0,0,0 ";

    return 0;
}
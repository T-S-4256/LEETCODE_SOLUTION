#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void printKaro(vector<vector<int>> ans)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i][0] << " : " << ans[i][1] << " : ";
        }
        cout<<endl;
    }
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {

        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i][0] < nums2[j][0])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i][0] > nums2[j][0])
            {
                ans.push_back(nums2[j]);
                j++;
            }
            else
            {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            cout<<"I = "<<i<<" J = "<<j<<endl;
        }
        printKaro(ans);
        while (j < nums2.size())
        {
            ans.push_back({nums2[j]});
            j++;
        }
        while (i < nums1.size())
        {
            ans.push_back({nums1[i]});
            i++;
        }
        return ans;
    }
};

int main()
{
    //     Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
    // Output: [[1,6],[2,3],[3,2],[4,6]]

    Solution s;
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};

    vector<vector<int>> ans;
    ans = s.mergeArrays(nums1, nums2);

    s.printKaro(ans);
    cout << "The Finel Output Is : [1,6],[2,3],[3,2],[4,6]";
    return 0;
}
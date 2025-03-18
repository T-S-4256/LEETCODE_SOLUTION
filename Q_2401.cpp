#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:

//ORDER OF N^4 COMPLEXITY SOLUTION 

    bool isNice(vector<int> nums, int start, int last)
    {
        for (int i = start; i < last; i++)
        {
            for (int j = i + 1; j <= last; j++)
            {
                cout << nums[i] << " & " << nums[j] << " : " << (nums[i] & nums[j]) << " : " << endl;
                if ((nums[i] & nums[j]))
                {
                    return false;
                }
            }
        }
        return true;
    }

    int bruthForceApproach(vector<int> &nums)
    {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (isNice(nums, i, j))
                {
                    maxi = max(maxi, (j - i) + 1);
                    cout << "i : " << i << " j : " << j << " Maxi : " << maxi << endl;
                }
                else
                {
                    cout << "Break" << endl;
                    break;
                }
            }
        }
        return maxi;
    }

    //ORDER OF N^3 COMPLEXITY SOLUTION 

    bool isNiceSubArray(vector<int> nums, int start, int last)
    {
        long long result = 0;
        for (int i = start; i <= last; i++)
        {
            if ((result & nums[i]) == 0)
            {
                result = (result | nums[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int optimized(vector<int> &nums)
    {
        int result = 1;
        for (int i = 0; i <= nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                cout << "I : " << i << "  J : " << j << " : ";
                if (isNiceSubArray(nums, i, j))
                {
                    result = max(result, (j - i) + 1);
                    cout << "Result Updated : " << result;
                }
                else
                {
                    cout << "Loop Breaked" << endl;
                    break;
                }
            }
        }
        return result;
    }

    // ORDER OF N^2 COMPLEXITY SOLUTION IT IS ACCETED ON LEETCODE  
    
    int moreOptimized(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            int check = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if ((check & nums[j]) == 0)
                {
                    check = (check | nums[j]);
                    cout << "I : " << i << " J : " << j << " Check : " << check << endl;
                }
                else
                {
                    result = max(result, (j - i));
                    cout << "Result Updated : " << result << endl;
                    break;
                }
                if ((j + 1) == nums.size())
                {

                    result = max(result, (j - i) + 1);
                    cout << "Result Updated On Compleate cycle : " << result << endl;
                }
            }
        }
        return result;
    }

    //ORDER OF N COMPLEXITY SOLUTION NOT TRIED ON LEETCODE 

    int longestNiceSubarray(vector<int> &nums)
    {
        int result = 1;
        int check = 0;
        int j = 0;
        int i = 0;
        while (j < nums.size()&& i < nums.size())
        {
            if ((check & nums[j]) == 0)
            {
                cout<<"I : "<<i<<" J : "<<j;
                result=max(result,(j-i)+1);
                check=(check | nums[j]);
                j++;
                cout<<" Result : "<<result<<" Check : "<<check<<endl;
            }
            else{
                cout<<"Nahi Hua :: ";
                check=(check^nums[i]);
                i++;
                cout<<"I : "<<i<<" J : "<<j<<" Result : "<<result<<" Check : "<<check<<endl;
            }
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: nums = [1,3,8,48,10]
    // Output: 3
    // CASE 2:
    // Input:
    // nums = [3,1,5,11,13]
    // Output: 1
    // CASE 3:
    // nums=[135745088,609245787,16,2048,2097152]
    // output :3
    Solution s;
    vector<int> nums = {135745088,609245787,16,2048,2097152};
    // cout << "Memory Limit Exceed On 65/52 : " << s.bruthForceApproach(nums);
    //  cout << "Time Limit Exceeded ": " << s.optimized(nums);
    // cout << "Ans : " << s.moreOptimized(nums);
    cout << s.longestNiceSubarray(nums)<<endl;

    return 0;
}
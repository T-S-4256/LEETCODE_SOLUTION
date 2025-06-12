#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=abs(nums[i]-nums[((i+1)%n)]);
            if(diff>max_diff){
                max_diff=diff;
            }
        }
        return max_diff;
    }
};




int main(){

    Solution s;
    vector<int> nums={1,2,4};
    cout<<"Ans : "<<s.maxAdjacentDistance(nums)<<endl;
    return 0;
}
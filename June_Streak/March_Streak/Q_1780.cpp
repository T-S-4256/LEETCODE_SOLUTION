#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int hPower = 0;
        for (int i = 0; i < n; i++)
        {
            if (pow(3, i) > n)
            {
                break;
            }
                hPower++;
        }

        while(n>0){
            if(n>=pow(3,hPower)){
                n-=pow(3,hPower);
            }
            if(n>=pow(3,hPower)){
                return false;
            }
            hPower--;
        }
        return true;
    }
};

int main()
{

    //     Input: n = 12
    // Output: true
    // Explanation: 12 = 31 + 32

    //     Input: n = 91
    // Output: true
    // Explanation: 91 = 30 + 32 + 34

    Solution s;
    int ans = s.checkPowersOfThree(12);
    cout << "Answer is : " << ans << endl;
    cout << "Expacted Answer  Is : true";
    return 0;
}
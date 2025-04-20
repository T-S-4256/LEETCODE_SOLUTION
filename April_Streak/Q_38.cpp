#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // BRUTH FORCE APPROACH
    string bruthForceApproach(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string ans = bruthForceApproach(n - 1);
        int count = 1;
        char number = ans[0];
        string result = "";
        for (int i = 1; i < ans.length(); i++)
        {
            if (ans[i] == number)
            {
                count++;
            }
            else
            {
                result = result + to_string(count) + number;
                number=ans[i];
                count=1;
            }
        }
        result = result + to_string(count) + number;
        return result;
    }
    // string countAndSay(int n)
    // {
    // }
};

int main()
{

    // CASE 1:
    // Input: n = 4
    // Output: "1211"
    // CASE 2:
    // Input: n = 1
    // Output: "1"

    Solution s;
    cout << "Ans  : " << s.bruthForceApproach(4);

    return 0;
}
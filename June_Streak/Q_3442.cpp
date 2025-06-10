#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxDifference(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            int val = s[i] - 'a';
            freq[val]++;
        }
        int evenNum = INT_MAX;
        int oddNum = INT_MIN;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;
            if (freq[i] % 2 == 0)
            {
                if (freq[i] < evenNum)
                {
                    evenNum = freq[i];
                }
            }
            else
            {
                if (freq[i] > oddNum)
                {
                    oddNum = freq[i];
                }
            }
        }
        // cout << "Min Even Num : " << evenNum << endl;
        // cout << "Max Odd Num :" << oddNum << endl;

        // cout << "The Frequency Of All The Character Are : " << endl;
        // for (int i = 0; i < 26; i++)
        // {
        //     cout << char(65 + i) << " : " << freq[i] << endl;
        // }

        return oddNum-evenNum;
    }
};

int main()
{

    Solution s;
    cout << "The Values Are : " << s.maxDifference("abcabcab");
    return 0;
}
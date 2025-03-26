#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int optimized(string s)
    {
        int ans = 0;
        int length = s.length();
        int minLen = -1;
        int positions[] = {-1, -1, -1};
        for (int i = 0; i < length; i++)
        {
            int pos =s[i]-97;
            positions[pos] = i;
            if (positions[0] != -1 && positions[1] != -1 && positions[2] != -1)
            {
                ans++;
                ans += min({positions[0], positions[1], positions[2]});
            }
            cout<<endl;
        }
        return ans;
    }

    int numberOfSubstrings(string s)
    {
        int ans = 0;
        unordered_map<char, int> mp;
        int length = s.length();
        int flag = 0;
        for (int i = 0; i <= length; i++)
        {
            for (int j = i; j < length; j++)
            {
                mp[s[j]]++;
                if (mp.size() == 3)
                {
                    flag = 1;
                    ans += length - j;
                    cout << "J : " << j << " Ans : " << ans << endl;
                    break;
                }
            }
            if (flag == 0)
            {
                return ans;
            }
            flag = 0;
            mp.clear();
        }
        return ans;
    }
};

int main()
{
    // CASE 1:
    // Input: s = "abcabc"
    // Output: 10

    // CASE 2:
    // Input: s = "aaacaaabaaab"
    // Output: 3

    // CASE 3:
    // Input: s = "abc"
    // Output: 1

    Solution s;
    cout<<"Time Exceeded At 53/54 :" << s.numberOfSubstrings("abcabc") << endl;
    cout << "Using Optimized Code : " << s.optimized("abcabc");

    return 0;
}
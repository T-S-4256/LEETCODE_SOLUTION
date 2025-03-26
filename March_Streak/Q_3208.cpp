#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool checkKaro(vector<int> &colors, int index, int k, int &flag)
    {
        int firstOccurance = colors[index];
        int length = colors.size();
        for (int i = 1; i < k; i++)
        {
            cout << firstOccurance << " : " << colors[(index + i) % length] << endl;
            if (colors[(index + i) % length] == firstOccurance)
            {
                flag = 0;
                return false;
            }
            firstOccurance = colors[(index + i) % length];
        }
        flag = 1;
        return true;
    }

    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int ans = 0;
        int flag = 1;
        int length = colors.size();
        checkKaro(colors, 0, k, flag) ? ans++ : ' ';
        for (int i = 1; i < colors.size(); i++)
        {
            cout << "Flag : " << flag << " : ";
            if (flag)
            {
                cout << "I : " << i << " first : " << colors[((i - 1 + k - 1) % length)] << " Last  : " << colors[((i + k - 1) % length)] << endl;
                if (colors[((i - 1 + k - 1) % length)] != colors[((i + k - 1) % length)])
                {
                    cout << "Badha Rha hu Bhai ";
                    ans++;
                }
                else
                {
                    i = i + k - 2;
                    cout << "Flag 0 Kar rha Hu " << " i : " << i;
                    flag = 0;
                }
            }
            else
            {
                cout << "Break Lag Gy Bhai :";
                checkKaro(colors, i, k, flag) ? ans++ : ' ';
            }
            cout << " Ans : " << ans << endl;
        }
        return ans;
    }
};

int main()
{
    // CASE 1:
    // nput: colors = [0,1,0,1,0], k = 3
    // Output: 3
    // CASE 2:
    // Input: colors = [0,1,0,0,1,0,1], k = 6
    // Output: 2
    // CASE 3 : Input : colors = [ 1, 1, 0, 1 ], k = 4
    // Output : 0
    // CASE 4:
    // Input : colors =[0,1,0,0,1]  K=3
    // OUTPUT:3

    Solution s;
    vector<int> num = {0, 1, 0, 0, 1};
    cout << endl
         << "Ans Is : " << endl;
    cout << s.numberOfAlternatingGroups(num, 3);

    return 0;
}
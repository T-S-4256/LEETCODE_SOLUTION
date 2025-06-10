#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    long long optimizedCode(int n)
    {
        return ((pow(n, 2)) + (pow((n - 1), 2)));
    }
    long long checkKaro(int n, long long ans, long counter)
    {
        if (n == 1)
        {
            return ans;
        }
        ans += counter;
        counter += 4;
        cout << "n : " << n << " counter : " << counter << " ans : " << ans << endl;
        return checkKaro(--n, ans, counter);
    }

    long long coloredCells(int n)
    {
        long long ans;
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            ans = checkKaro(n, 1, 4);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << endl;
    cout<<"ANSWER THROUGH BRUTH FORCE APPROACH : " << s.coloredCells(86)<<endl;
    cout<<"OPTIMIZED CODE : "<<s.optimizedCode(86);

    return 0;
}
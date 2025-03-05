#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool checkSumOfPowerIsNumber(int num)
    {
        int hPower = 0;
        for (int i = 0; i <= num; i++)
        {
            if (pow(3, i) > num)
            {
                break;
            }
            hPower++;
        }
        while (num > 0)
        {
            if (num <= pow(3, hPower))
            {
                num -= pow(3, hPower);
            }
            if (num <= pow(3, hPower))
            {
                return false;
            }
            hPower--;
        }
        return true;
    }
};
int main()
{
    return 0;
}
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
//VECTOR KE VALUE PRINT KARNE KE LIYE BAR BAR LOOP LAGANE KI JAROORAT NHI HAI
    void printKaro(vector<int> num)
    {
        for (int i = 0; i < num.size(); i++)
        {
            cout << num[i] << " : ";
        }
        cout << endl;
    }
    //CHECK IS THE GIVEN NUMBER IS PRIME OR NOT ??
    bool checkPrime(int num)
    {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
//FIND ALL THE PRIME NUMBER BETWEEN A RANGE FIRST TO LAST
    vector<int> findPrime(int first, int last)
    {
        vector<int> possibility;
        for (int i = first; i <= last; i++)
        {
            if (checkPrime(i))
            {
                possibility.push_back(i);
            }
        }
        return possibility;
    }
    //NOW FIND THE CLOSEST PRIME NUMBER PAIR
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> possiblePrime;
        possiblePrime = findPrime(left, right);
        // cout<<"In ClosestPrime Possible Primes Are : ";
        // printKaro(possiblePrime);
        if (possiblePrime.size() < 2)
            return {-1, -1};
        int closest = 10000;
        vector<int> ans = {-1, -1};
        for (int i = 0; i < possiblePrime.size() - 1; i++)
        {
            if (abs(possiblePrime[i] - possiblePrime[i + 1]) < closest)
            {
                closest = abs(possiblePrime[i] - possiblePrime[i + 1]);
                ans[0] = possiblePrime[i];
                ans[1] = possiblePrime[i + 1];
            }
        }
        return ans;
    }
};

int main()
{
    // CASE 1:
    // Input: left = 10, right = 19
    // Output: [11,13]

    // CASE 2:
    // Input: left = 4, right = 6
    // Output: [-1,-1]

    Solution s;
    vector<int> ans;
    ans = s.closestPrimes(10, 19);
    s.printKaro(ans);
    cout << "Expected Output Is : 11 13 ";
    return 0;
}
#include <iostream>
using namespace std;

class Solution
{
public:
long long BruthForce(int n, int limit)
    {
        long long ways=0;
        for(int i=0;i<=min(n,limit);i++){
            for(int j=0;j<=min((n-i),limit);j++){
                for(int k=0;k<=min(n-(i+j),limit);k++){
                    if (i+j+k==n){
                        ways++;
                    }
                }
            }
        }
        return ways;
    }
    long long optimized(int n, int limit)
    {
        long long ways=0;
        for(int i=0;i<=min(n,limit);i++){
            for(int j=0;j<=min((n-i),limit);j++){
                int k=((n-i-j),limit);
                    if (i+j+k==n){
                        cout<<"I : "<<i<<" J : "<<j<<" K : "<<k<<endl;
                        ways++;
                    }
            }
        }
        return ways;
    }
    long long distributeCandies(int n, int limit)
    {
        long long ways = 0;

        //child1
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { //fixing child1 assignment of candies

            int N = n-i; //for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};

int main()
{
    // CASE 1:
    // Input: n = 5, limit = 2
    // Output: 3
    // CASE 2:
    // Input: n = 3, limit = 3
    // Output: 10
    Solution s;
    cout<<"Ans : "<<s.optimized(5,2);

    return 0;
}
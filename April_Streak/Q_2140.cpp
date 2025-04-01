#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long solve(int i, vector<vector<int>> &questions, vector<long long> &memo)
    {
        if (i >= questions.size())
        {
            return 0;
        }
        if (memo[i] != -1)
        {
            return memo[i];
        }
        long long take = questions[i][0] + solve((i + questions[i][1] + 1), questions, memo);
        long long not_take = solve(i + 1, questions, memo);
        return memo[i] = max(take, not_take);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> memo(n, -1);
        return solve(0, questions, memo);
    }
};

int main()
{
    // CASE 1:
    // Input: questions = {{3,2},{4,3},{4,4},{2,5}}
    // Output: 5
    // CASE 2:
    // Input: questions = {{1,1},{2,2},{3,3},{4,4},{5,5}}
    // Output: 7
    // CASE 3:

    Solution s;
    // vector<vector<int>> questions={{3,2},{4,3},{4,4},{2,5}};
    vector<vector<int>> questions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << "The Answer Is : " << s.mostPoints(questions);
    return 0;
}
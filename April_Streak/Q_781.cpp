#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;
        int result = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            if (mp[answers[i]] == 0)
            {
                result = result + answers[i] + 1;
                mp[answers[i]]++;
            }
            else if (mp[answers[i]] == answers[i]+1)
            {
                result = result + answers[i] + 1;
                mp[answers[i]] = 1;
            }
            else
            {
                mp[answers[i]]++;
            }
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: answers = [1,1,2]
    // Output: 5
    // CASE 2:
    // Input: answers = [10,10,10]
    // Output: 11
    Solution s;
    vector<int> answers = {10,10,10};
    cout << "Answer Is : " << s.numRabbits(answers);

    return 0;
}
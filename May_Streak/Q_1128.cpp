#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int bruthForce(vector<vector<int>> &dominoes)
    {
        int count = 0;
        for (int i = 0; i < dominoes.size() - 1; i++)
        {
            for (int j = i + 1; j < dominoes.size(); j++)
            {
                if (dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1] || dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0])
                {
                    count++;
                }
            }
        }
        return count;
    }

    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int count = 0;
        unordered_map<int, int> mp;
        for (auto &pair : dominoes)
        {
            int a = pair[0], b = pair[1];
            int num = a < b ? a * 10 + b : b * 10 + b;
            count += mp[num];
            mp[num]++;
            cout << "Count : " << count << " MP : " << mp[num] << endl;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
    cout << "Ans : " << s.numEquivDominoPairs(nums);
    return 0;
}
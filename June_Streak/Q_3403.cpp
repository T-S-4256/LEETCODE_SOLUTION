#include <iostream>
using namespace std;

class Solution
{
public:
    string answerString(string word, int numFriends)
    {

        char letter;
        int min = 0;
        // FINDING THE GREATEST CHARACTER
        for (int i = 0; i < word.length(); i++)
        {
            if (int(word[i]) > min)
            {
                min = int(word[i]);
                letter = word[i];
            }
        }
        cout << "Greatest Character : " << letter << endl;
        string ans;
        min = -1;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == letter)
            {
                int friends = numFriends - i - 1;
                if (friends < 0)
                {
                    friends = 0;
                }
                int encode = 0;
                for (int j = i; j < word.length() - (friends - 1); j++)
                {
                    encode = encode * 100 + (word[j] - 'a' + 1);
                }
                if (encode > min)
                {
                    int length = word.length() - i;
                    ans = word.substr(i, length);
                }
                cout << "Encode : " << encode << " Word : " << ans << endl;
            }
        }
        return "Satyam";
    }
};

int main()
{
    Solution s;
    // cout << "Ans : " << s.answerString("dbca", 2);
    cout << "Ans : " << s.answerString("gggg", 4);

    return 0;
}
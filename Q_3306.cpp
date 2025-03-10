#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isVowel(char s)
    {
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
    }

    long long countAtLeastK(const string word, int k)
    {
        long long validCount = 0;
        int left = 0, right = 0, consonentCount = 0;
        unordered_map<char, int> vowelFreq;
        while (right < word.length())
        {
            if (isVowel(word[right]))
            {
                vowelFreq[word[right]]++;
            }
            else
            {
                consonentCount++;
            }
            while (vowelFreq.size() == 5 && consonentCount >= k)
            {
                validCount += word.length() - right;
                if (isVowel(word[left]))
                {
                    if (--vowelFreq[word[left]] == 0)
                    {
                        vowelFreq.erase(word[left]);
                    }
                }
                else
                {
                    consonentCount--;
                }
                left++;
            }
            right++;
        }
        return validCount;
    }
    long long optimized(string word, int k)
    {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }
    void print_karo(vector<int> num)
    {
        for (int i = 0; i < num.size(); i++)
        {
            cout << num[i] << " : ";
        }
        cout << endl;
    }
    long long countOfSubstrings(string word, int k)
    {
        int length = word.length();
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        for (int j = 0; j < length; j++)
        {
            if (word[j] == 'a')
            {
                a++;
            }
            else if (word[j] == 'e')
            {
                e++;
            }
            else if (word[j] == 'i')
            {
                i++;
            }
            else if (word[j] == 'o')
            {
                o++;
            }
            else if (word[j] == 'u')
            {
                u++;
            }
        }
        if (!(a > 0 && e > 0 && i > 0 && o > 0 && u > 0) || length < 5)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i <= length - 5; i++)
        {
            vector<int> temp = {97, 101, 105, 111, 117};
            int constant = 0;
            for (int j = i; j < length; j++)
            {
                print_karo(temp);
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
                {
                    if (temp.size() > 0)
                    {
                        temp.erase(remove(temp.begin(), temp.end(), int(word[j])), temp.end());
                    }
                    if (temp.size() == 0 && constant == k || temp.size() == 0 && constant == k && j == length - 1)
                    {
                        ans++;
                    }
                }
                else
                {
                    constant++;
                    if (temp.size() == 0 && constant == k)
                    {
                        ans++;
                    }
                    else if (constant > k)
                    {
                        for (int k = i; k <= j; k++)
                        {
                            if (!(word[k] == 'a' || word[k] == 'e' || word[k] == 'i' || word[k] == 'o' || word[k] == 'u'))
                            {
                                i = k;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    // CASEC 1:
    // Input: word = "aeioqq", k = 1
    // Output: 0

    // CASE 2:
    // Input: word = "aeiou", k = 0
    // Output: 1

    // CASE 3:
    // Input: word = "ieaouqqieaouqq", k = 1
    // Output: 3

    // CASE 4:
    // iqeaouqi,2
    // 3

    Solution s;
    cout << " Time Limit Excedded at  case :758/768 Ans : " << s.countOfSubstrings("aeiou", 0) << endl;
    cout << "Ans : " << s.optimized("aeiou", 0);

    return 0;
}
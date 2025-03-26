#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void print_karo(vector<vector<int>> &rectangles)
    {
        for (int i = 0; i < rectangles.size(); i++)
        {
            for (int j = 0; j < rectangles[i].size(); j++)
            {
                cout << rectangles[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool more_optimized(int n, vector<vector<int>> &rectangles)
    {
        vector<pair<int, int>> storage(rectangles.size());

        for (int i = 0; i < rectangles.size(); i++)
        {
            storage[i] = {rectangles[i][1], rectangles[i][3]};
        }

        sort(storage.begin(), storage.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                     return a.second < b.second; // Sort by second if first elements are equal
                 return a.first < b.first;       // Otherwise, sort by the first element
             });

        // for (int i = 0; i < storage.size(); i++)
        // {
        //     cout << storage[i].first << " : " << storage[i].second << endl;
        // }
        int first = storage[0].first;
        int last = storage[0].second;
        int count = 0;

        for (int i = 1; i < storage.size(); i++)
        {
            cout << "First : " << first << " Second : " << last << " : ";
            if (storage[i].first < last)
            {
                cout << "First ";
                if (storage[i].second > last)
                {
                    cout << "Second ";
                    last = storage[i].second;
                }
                cout << endl;
            }
            else
            {
                first = storage[i].first;
                last = storage[i].second;
                count++;
                cout << " Count : " << count << endl;
                if (count == 2)
                    return true;
            }
        }



        for (int i = 0; i < rectangles.size(); i++)
        {
            storage[i] = {rectangles[i][0], rectangles[i][2]};
        }

        sort(storage.begin(), storage.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                     return a.second < b.second; // Sort by second if first elements are equal
                 return a.first < b.first;       // Otherwise, sort by the first element
             });

             count=0;
        first=storage[0].first;
        last=storage[0].second;
        for (int i = 1; i < storage.size(); i++)
        {
            cout << "First : " << first << " Second : " << last << " : ";
            if (storage[i].first < last)
            {
                cout << "First ";
                if (storage[i].second > last)
                {
                    cout << "Second ";
                    last = storage[i].second;
                }
                cout << endl;
            }
            else
            {
                first = storage[i].first;
                last = storage[i].second;
                count++;
                cout << " Count : " << count << endl;
                if (count == 2)
                    return true;
            }
        }
        return false;
    }

    bool optimized(int n, vector<vector<int>> &rectangles)
    {
        int count = 0;
        // FOR HORIZONTAL VERIFICATION
        std::sort(rectangles.begin(), rectangles.end(), [](const std::vector<int> &a, const std::vector<int> &b)
                  {
                      return a[3] < b[3]; // Ascending order based on index 2
                  });
        cout << "The Sorted Are : " << endl;
        print_karo(rectangles);
        int check = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            int flag = 0;
            if (rectangles[i][3] == n)
            {
                break;
            }
            if (rectangles[i][3] > check)
            {
                cout << "Check Updated : ";
                check = rectangles[i][3];
            }
            else
            {
                cout << "Goes On Continue : " << endl;
                continue;
            }
            cout << " Check : " << check << " ";
            for (int j = 0; j < rectangles.size(); j++)
            {
                if (j == i)
                {
                    cout << "First If Enter ";
                    continue;
                }
                if (rectangles[j][1] < check && check < rectangles[j][3])
                {
                    cout << "Sencond If For Flag Updated " << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    cout << " Nah ";
                }
            }
            if (flag == 0)
            {
                cout << "Flag 0 Count Updated ";
                count++;
                cout << "Count : " << count << " " << endl;
                if (count == 2)
                {
                    cout << " Return Done ";
                    return true;
                }
            }
        }

        check = 0;
        count = 0;
        std::sort(rectangles.begin(), rectangles.end(), [](const std::vector<int> &a, const std::vector<int> &b)
                  {
                      return a[2] < b[2]; // Ascending order based on index 2
                  });
        cout << "The Sorted Are : " << endl;
        print_karo(rectangles);
        // FOR VERTICLE VERIFICATION
        cout << "Bhai Verticle KAr Rha ";
        for (int i = 0; i < rectangles.size(); i++)
        {
            int flag = 0;
            if (rectangles[i][2] == n)
            {
                break;
            }
            if (rectangles[i][2] > check)
            {
                cout << "Check Updated : ";
                check = rectangles[i][2];
            }
            else
            {
                cout << "Goes On Continue : " << endl;
                continue;
            }
            cout << " Check : " << check << " ";
            for (int j = 0; j < rectangles.size(); j++)
            {
                if (j == i)
                {
                    cout << "First If Enter ";
                    continue;
                }
                if (rectangles[j][0] < check && check < rectangles[j][2])
                {
                    cout << "Sencond If For Flag Updated " << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    cout << " Nah ";
                }
            }
            if (flag == 0)
            {
                cout << "Flag 0 Count Updated ";
                count++;
                cout << "Count : " << count << " " << endl;
                if (count == 2)
                {
                    cout << " Return Done ";
                    return true;
                }
            }
        }
    }

    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        int count = 0;
        int lastSection = 0;
        // HORIZONTAL CHECK
        for (int i = 1; i < n; i++)
        {
            cout << "Enter ";
            bool rectangleFlag = false;
            int flag = 0;
            for (int j = 0; j < rectangles.size(); j++)
            {
                cout << " I : " << i << " J : " << j << " 2nd Enter ";
                if (rectangles[j][3] > i)
                {
                    cout << " Fist IF ";
                    if (rectangles[j][1] < i)
                    {
                        cout << " Update Flag ";
                        flag = 1;
                    }
                }
                else
                {
                    if (rectangles[j][1] >= lastSection)
                    {
                        cout << " " << rectangles[j][1] << " : " << lastSection << " ";
                        rectangleFlag = true;
                        cout << " Rectangle Flag Updated ";
                    }
                }
                if (flag == 1)
                {
                    cout << endl;
                    break;
                }
            }

            if (flag == 0)
            {
                count++;
                lastSection = i;
                if (count == 2 && rectangleFlag == true)
                {
                    cout << " Enter Return " << "Count : " << count << endl;
                    return true;
                }
            }
            cout << "Count : " << count << " " << endl;
        }

        cout << "Ab Verticle check Kar Rhe Hai" << endl;
        // VERTICLE CHECK
        count = 0;
        lastSection = 0;
        for (int i = 1; i < n; i++)
        {
            bool rectangleFlag = false;
            cout << "Enter ";
            int flag = 0;
            for (int j = 0; j < rectangles.size(); j++)
            {
                cout << " I : " << i << " J : " << j << " 2nd Enter ";
                if (rectangles[j][2] > i)
                {
                    cout << " Fist IF ";
                    if (rectangles[j][0] < i)
                    {
                        cout << " Update Flag ";
                        flag = 1;
                    }
                }
                else
                {
                    if (rectangles[j][0] >= lastSection)
                    {
                        cout << " " << rectangles[j][1] << " : " << lastSection << " ";
                        rectangleFlag = true;
                        cout << " Rectangle Flag Updated ";
                    }
                }
                if (flag == 1)
                {
                    cout << endl;
                    break;
                }
            }

            if (flag == 0)
            {
                count++;
                lastSection = i;
                if (count == 2 && rectangleFlag == true)
                {
                    cout << " Enter Return " << "Count : " << count << endl;
                    return true;
                }
            }
            cout << "Count : " << count << " " << endl;
        }

        return false;
    }
};

int main()
{
    // CASE 1:
    // Input: n = 5, rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}}
    // Output: true
    // CASE 2:
    // Input: n = 4, rectangles = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}}
    // Output: true
    // CASE 3:
    // Input: n = 6, rectangles = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}}
    // Output: false
    // CASE 4:
    // Input: n = 4, rectangles = {{4,0,5,2},{0,5,4,6},{4,5,6,6}};
    // Output: false

    Solution s;
    vector<vector<int>> rectangle = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    // vector<vector<int>> rectangle = {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
    // vector<vector<int>> rectangle = {{0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
    // vector<vector<int>> rectangle = {{4, 0, 5, 2}, {0, 5, 4, 6}, {4, 5, 6, 6}};
    // cout << "The Answer Is : " << s.checkValidCuts(6, rectangle); APPROX 20 TO 25 TEST CASE REMAIN TIME EXCEDDED
    // cout << "The Answer Is : " << s.optimized(4, rectangle);      APPROX 20 TO 25 TEST CASE REMAIN TIME EXCEDDED
    cout << "The Answer Is : " << s.more_optimized(5, rectangle);

    return 0;
}
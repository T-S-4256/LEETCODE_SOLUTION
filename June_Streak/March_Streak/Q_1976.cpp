#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    typedef pair<long long, int> P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto &vertex : roads)
        {
            int u = vertex[0];
            int v = vertex[1];
            int charge = vertex[2];
            mp[u].push_back({v, charge});
            mp[v].push_back({u, charge});
        }

        // for (auto &ngbr : mp)
        // {
        //     cout << ngbr.first << " :: ";
        //     for (int i = 0; i < ngbr.second.size(); i++)
        //     {
        //         cout << " [ ";
        //         for (int j = 0; j < ngbr.second[i].size(); j++)
        //         {
        //             cout << ngbr.second[i][j] << " : ";
        //         }
        //         cout << " ]  ";
        //     }
        //     cout << endl;
        // }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!(pq.empty()))
        {
            long long currTime = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for (auto &vec : mp[currNode])
            {
                int ngbr = vec.first;
                int roadTime = vec.second;

                if (currTime + roadTime < result[ngbr])
                {
                    result[ngbr] = currTime + roadTime;
                    pq.push({result[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                }
                else if (currTime + roadTime == result[ngbr])
                {
                    pathCount[ngbr] = (pathCount[currNode] + pathCount[ngbr]) % M;
                }
            }
        }
        return pathCount[n - 1];
    }
};

int main()
{

    // CASE 1:
    // Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    // Output: 4
    // CASE 2:
    // Input: n = 2, roads = [[1,0,10]]
    // Output: 1
    // CASE 3:

    Solution s;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    cout<<"Ans : "<<s.countPaths(7, roads);

    return 0;
}
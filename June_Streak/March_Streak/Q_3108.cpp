#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> parent;
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        parent.resize(n);
        vector<int> cost(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            cost[i] = -1;
        }
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v)
            {
                Union(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
        }

        vector<int> result;
        for (auto &q : query)
        {
            int s = q[0];
            int t = q[1];
            int parent_s = find(s);
            int parent_t = find(t);
            if (s == t)
            {
                result.push_back(0);
            }
            else if (parent_s != parent_t)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(cost[parent_s]);
            }
        }
        return result;
    }
};

int main()
{

    // CASE 1:
    // Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
    // Output: [1,-1]
    // CASE 2:
    // Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
    // Output: [0]
    // CASE 3:
    Solution s;
    vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
    vector<vector<int>> query = {{0, 3}, {3, 4}};
    vector<int> ans;
    ans = s.minimumCost(5, edges, query);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " : ";
    }

    return 0;
}
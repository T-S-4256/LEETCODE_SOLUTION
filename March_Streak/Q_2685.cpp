#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    // CODE FOR BREADTH FIRST SEARCH
    void bfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &e, int &v)
    {
        queue<int> que;
        que.push(i);

        while (!que.empty())
        {
            int curr = que.front();
            que.pop();
            visited[curr] = true;
            v++;
            e += adj[curr].size();
            for (auto &ngbr : adj[curr])
            {
                if (!visited[ngbr])
                {
                    visited[ngbr]=true;
                    que.push(ngbr);
                    // bfs(ngbr, adj, visited, e, v);
                }
            }
        }
    }

    // CODE FOR DEPTH FIRST SEARCH
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &e, int &v)
    {
        visited[i] = true;
        v++;
        e += adj[i].size();
        // cout << "Edge : " << e << " ";
        for (int &ngbr : adj[i])
        {
            if (!visited[ngbr])
            {
                dfs(ngbr, adj, visited, e, v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int result = 0;
        unordered_map<int, vector<int>> adj;
        // CREATING THE GRAPH
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // cout<<"Adj : "<<endl;
        // for (auto &edge : adj)
        // {
        //     cout<<endl;
        //     cout<<edge.first<<" :: ";
        //     for(auto& e : edge.second){
        //         cout<<e<<" ";
        //     }
        // }
        // cout<<endl;
        // CHECK FOR VERTEX IS VISITED OR NOT
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
            {
                continue;
            }
            int e = 0;
            int v = 0;

            // WE HAVE TWO METHOD FOR TRAVERSING
            // 1.BFS
            // 2.DFS

            // dfs(i, adj, visited, e, v);
            bfs(i, adj, visited, e, v);

            if ((v * (v - 1)) == e)
            {
                result++;
            }
        }
        return result;
    }
};

int main()
{
    // CASE 1:
    // Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    // Output: 3
    // CASE 2:
    // Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
    // Output: 1
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << s.countCompleteComponents(6, edges);

    return 0;
}
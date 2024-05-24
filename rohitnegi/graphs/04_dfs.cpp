#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs_solver(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &ans)
{
    visited[node] = true;
    ans.push_back(node);
    for (int i : adjList[node])
    {
        if (!visited[i])
        {
            dfs_solver(i, adjList, visited, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>> adjList)
{
    vector<int> ans;
    vector<bool> visited(adjList.size(), false);
    dfs_solver(0, adjList, visited, ans);
    return ans;
}

int main()
{
    vector<vector<int>> adjList = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = dfs(adjList);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
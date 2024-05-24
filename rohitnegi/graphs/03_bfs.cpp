#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> adjList)
{
    vector<int> ans;
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    visited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (int i : adjList[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> ans = bfs({{1, 2, 3}, {}, {4}, {}, {}});
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
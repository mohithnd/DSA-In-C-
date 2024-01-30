#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_list(vector<vector<int>> list)
{
    cout << "Adjacency List:-" << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> adjacency_list(int n, int m, vector<pair<int, int>> pairs, bool directed)
{
    vector<vector<int>> adj_list(n);
    for (pair<int, int> p : pairs)
    {
        adj_list[p.first].push_back(p.second);
        if (!directed)
        {
            adj_list[p.second].push_back(p.first);
        }
    }
    return adj_list;
}

void bfs_connected_components(vector<vector<int>> adj_list)
{
    vector<bool> visited(adj_list.size() + 1, false);
    queue<int> q;
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                cout << node << " ";
                for (int i : adj_list[node])
                {
                    if (!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

void bfs(vector<vector<int>> adj_list, bool connected_components = false)
{
    if (connected_components)
    {
        bfs_connected_components(adj_list);
        return;
    }
    vector<bool> visited(adj_list.size() + 1, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i : adj_list[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n = 8;
    int m = 7;
    vector<pair<int, int>> pairs = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}};
    vector<vector<int>> adj_list = adjacency_list(n, m, pairs, false);
    print_list(adj_list);
    bfs(adj_list);

    cout << endl;

    n = 5;
    m = 4;
    pairs = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    adj_list = adjacency_list(n, m, pairs, false);
    print_list(adj_list);
    bfs(adj_list, true);
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_matrix(vector<vector<int>> matrix)
{
    cout << "Adjacency Matrix:-" << endl;
    for (auto row : matrix)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

vector<vector<int>> adjacency_matrix(int n, int m, vector<pair<int, int>> pairs, bool directed)
{
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for (pair<int, int> p : pairs)
    {
        adj_matrix[p.first][p.second] = 1;
        if (!directed)
        {
            adj_matrix[p.second][p.first] = 1;
        }
    }
    return adj_matrix;
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

void solve_dfs(vector<vector<int>> adj_list, int node, vector<bool> &visited, vector<int> &ans)
{
    visited[node] = true;
    ans.push_back(node);
    for (int i : adj_list[node])
    {
        if (!visited[i])
        {
            solve_dfs(adj_list, i, visited, ans);
        }
    }
}

void dfs_connected(vector<vector<int>> adj_list)
{
    vector<vector<int>> ans;
    vector<bool> visited(adj_list.size(), false);
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            solve_dfs(adj_list, i, visited, temp);
            ans.push_back(temp);
        }
    }
    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<vector<int>> adj_list, bool connected = false)
{
    if (connected)
    {
        dfs_connected(adj_list);
        return;
    }
    vector<int> ans;
    vector<bool> visited(adj_list.size(), false);
    solve_dfs(adj_list, 0, visited, ans);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adj_list = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    print_list(adj_list);
    dfs(adj_list);

    cout << endl;

    int n = 5;
    int m = 4;
    vector<pair<int, int>> pairs = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    adj_list = adjacency_list(n, m, pairs, false);
    print_list(adj_list);
    dfs(adj_list, true);
    return 0;
}
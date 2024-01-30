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

vector<vector<int>> adjacency_list_from_adjacency_matrix(vector<vector<int>> adj_matrix)
{
    vector<vector<int>> adj_list(adj_matrix.size());
    for (int i = 0; i < adj_matrix.size(); i++)
    {
        for (int j = 0; j < adj_matrix[i].size(); j++)
        {
            if (adj_matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }
    return adj_list;
}

void solve(vector<vector<int>> adj_list, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if (!visited[adj_list[node][i]])
        {
            solve(adj_list, visited, adj_list[node][i]);
        }
    }
}

int number_of_provinces_dfs(vector<vector<int>> adj_list)
{
    int ans = 0;
    vector<bool> visited(adj_list.size(), false);
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            ans++;
            solve(adj_list, visited, i);
        }
    }
    return ans;
}

int number_of_provinces_bfs(vector<vector<int>> adj_list)
{
    int ans = 0;
    vector<bool> visited(adj_list.size(), false);
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            ans++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int i = 0; i < adj_list[node].size(); i++)
                {
                    if (!visited[adj_list[node][i]])
                    {
                        q.push(adj_list[node][i]);
                        visited[adj_list[node][i]] = true;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> roads = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    roads = adjacency_list_from_adjacency_matrix(roads);
    print_list(roads);
    cout << number_of_provinces_dfs(roads) << endl;
    cout << number_of_provinces_bfs(roads) << endl;

    cout << endl;

    roads = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    roads = adjacency_list_from_adjacency_matrix(roads);
    print_list(roads);
    cout << number_of_provinces_dfs(roads) << endl;
    cout << number_of_provinces_bfs(roads) << endl;
    return 0;
}
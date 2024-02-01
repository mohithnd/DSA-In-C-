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

void print_grid(vector<vector<int>> grid)
{
    for (vector<int> i : grid)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int rotten_oranges_bfs(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    int ans = 0;
    vector<int> del_rows = {-1, 1, 0, 0};
    vector<int> del_cols = {0, 0, -1, 1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        q.pop();
        ans = max(ans, time);
        for (int i = 0; i < 4; i++)
        {
            int nr = r + del_rows[i];
            int nc = c + del_cols[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                q.push({{nr, nc}, time + 1});
                visited[nr][nc] = true;
                grid[nr][nc] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    print_grid(grid);
    cout << rotten_oranges_bfs(grid) << endl;
    grid = {{2, 2, 0, 1}};
    print_grid(grid);
    cout << rotten_oranges_bfs(grid) << endl;
    return 0;
}
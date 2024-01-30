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

int number_of_islands_bfs(vector<vector<int>> grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for (int r = x - 1; r <= x + 1; r++)
                    {
                        for (int c = y - 1; c <= y + 1; c++)
                        {
                            if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && grid[r][c] == 1)
                            {
                                q.push({r, c});
                                visited[r][c] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    cout << number_of_islands_bfs(grid) << endl;
    grid = {{0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};
    cout << number_of_islands_bfs(grid) << endl;
    return 0;
}
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

vector<vector<int>> flood_fill_bfs(vector<vector<int>> image, int sr, int sc, int new_color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int old_color = image[sc][sr];
    visited[sr][sc] = true;
    image[sr][sc] = new_color;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first;
        int c = p.second;
        int nr, nc;
        nr = r - 1, nc = c;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && (image[nr][nc] == old_color))
        {
            visited[nr][nc] = true;
            image[nr][nc] = new_color;
            q.push({nr, nc});
        }
        nr = r + 1, nc = c;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && (image[nr][nc] == old_color))
        {
            visited[nr][nc] = true;
            image[nr][nc] = new_color;
            q.push({nr, nc});
        }
        nr = r, nc = c - 1;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && (image[nr][nc] == old_color))
        {
            visited[nr][nc] = true;
            image[nr][nc] = new_color;
            q.push({nr, nc});
        }
        nr = r, nc = c + 1;
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && (image[nr][nc] == old_color))
        {
            visited[nr][nc] = true;
            image[nr][nc] = new_color;
            q.push({nr, nc});
        }
    }
    return image;
}

void solve_flood_fill_dfs(vector<vector<int>> &image, int r, int c, int new_color, int old_color, vector<vector<bool>> &visited)
{
    visited[r][c] = true;
    image[r][c] = new_color;
    int nr, nc;
    nr = r - 1, nc = c;
    if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && !visited[nr][nc] && (image[nr][nc] == old_color))
    {
        solve_flood_fill_dfs(image, nr, nc, new_color, old_color, visited);
    }
    nr = r + 1, nc = c;
    if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && !visited[nr][nc] && (image[nr][nc] == old_color))
    {
        solve_flood_fill_dfs(image, nr, nc, new_color, old_color, visited);
    }
    nr = r, nc = c - 1;
    if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && !visited[nr][nc] && (image[nr][nc] == old_color))
    {
        solve_flood_fill_dfs(image, nr, nc, new_color, old_color, visited);
    }
    nr = r, nc = c + 1;
    if (nr >= 0 && nc >= 0 && nr < image.size() && nc < image[0].size() && !visited[nr][nc] && (image[nr][nc] == old_color))
    {
        solve_flood_fill_dfs(image, nr, nc, new_color, old_color, visited);
    }
}

vector<vector<int>> flood_fill_dfs(vector<vector<int>> image, int sr, int sc, int new_color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int old_color = image[sr][sc];
    solve_flood_fill_dfs(image, sr, sc, new_color, old_color, visited);
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    print_grid(image);
    int sr = 1;
    int sc = 1;
    int new_color = 2;
    print_grid(flood_fill_bfs(image, sr, sc, new_color));
    print_grid(flood_fill_dfs(image, sr, sc, new_color));
    return 0;
}
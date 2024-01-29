#include <iostream>
#include <vector>
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

int main()
{
    int n = 8;
    int m = 7;
    vector<pair<int, int>> pairs = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}};

    cout << "Undirected Graph" << endl;
    vector<vector<int>> adj_matrix = adjacency_matrix(n, m, pairs, false);
    print_matrix(adj_matrix);
    vector<vector<int>> adj_list = adjacency_list(n, m, pairs, false);
    print_list(adj_list);
    cout << endl;

    cout << "Directed Graph" << endl;
    adj_matrix = adjacency_matrix(n, m, pairs, true);
    print_matrix(adj_matrix);
    adj_list = adjacency_list(n, m, pairs, true);
    print_list(adj_list);
    return 0;
}
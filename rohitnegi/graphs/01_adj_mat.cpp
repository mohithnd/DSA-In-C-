#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    // // undirected unweighted
    // vector<vector<bool>> mat(vertex, vector<bool>(vertex, 0));

    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     mat[u][v] = 1;
    //     mat[v][u] = 1;
    // }

    // // undirected weighted
    // vector<vector<int>> mat(vertex, vector<int>(vertex, 0));

    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     mat[u][v] = w;
    //     mat[v][u] = w;
    // }

    // // directed unweighted
    // vector<vector<bool>> mat(vertex, vector<bool>(vertex, 0));

    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     mat[u][v] = 1;
    // }

    // directed weighted
    vector<vector<int>> mat(vertex, vector<int>(vertex, 0));

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }

    // printing
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
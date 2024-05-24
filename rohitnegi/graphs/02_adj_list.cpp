#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;

    // // undirected unweighted
    // vector<vector<int>> list(vertex);
    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     list[u].push_back(v);
    //     list[v].push_back(u);
    // }

    // // undirected weighted
    // vector<vector<pair<int, int>>> list(vertex);
    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     list[u].push_back({v, w});
    //     list[v].push_back({u, w});
    // }

    // // directed unweighted
    // vector<vector<int>> list(vertex);
    // for (int i = 0; i < edge; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     list[u].push_back(v);
    // }

    // directed weighted
    vector<vector<pair<int, int>>> list(vertex);
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list[u].push_back({v, w});
    }

    // // printing unweighted
    // for (int i = 0; i < vertex; i++)
    // {
    //     for (int j : list[i])
    //     {
    //         cout << j << endl;
    //     }
    //     cout << endl;
    // }

    // printing weighted
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> j : list[i])
        {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << endl;
    }

    return 0;
}
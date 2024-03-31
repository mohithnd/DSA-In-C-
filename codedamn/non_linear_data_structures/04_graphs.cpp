#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    string data;
    Node(string data)
    {
        this->data = data;
    }
};

enum GRAPH_DIRECTION
{
    DIRECTED,
    UNDIRECTED
};

class Graph
{
public:
    unordered_map<Node *, vector<Node *>> adjacency_list;
    map<string, Node *> nodes;

    Node *create_node(string data)
    {
        if (nodes.find(data) == nodes.end())
        {
            nodes[data] = new Node(data);
        }
        return nodes[data];
    }

    void create_connection(Node *from, Node *to, GRAPH_DIRECTION direction)
    {
        if (adjacency_list.find(from) == adjacency_list.end())
        {
            adjacency_list[from] = vector<Node *>();
        }
        if (adjacency_list.find(to) == adjacency_list.end())
        {
            adjacency_list[to] = vector<Node *>();
        }
        adjacency_list[from].push_back(to);
        if (direction == UNDIRECTED)
        {
            adjacency_list[to].push_back(from);
        }
    }

    bool empty()
    {
        return adjacency_list.empty();
    }

    void bfs(Node *start)
    {
        if (empty())
        {
            cout << "Graph Is Empty" << endl;
            return;
        }
        queue<Node *> q;
        unordered_map<Node *, bool> visited;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            for (Node *i : adjacency_list[curr])
            {
                if (visited[i] == false)
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(Node *curr, unordered_map<Node *, bool> &visited)
    {
        cout << curr->data << " ";
        visited[curr] = true;
        for (Node *i : adjacency_list[curr])
        {
            if (visited[i] == false)
            {
                dfs(i, visited);
            }
        }
    }

    void dfs(Node *start)
    {
        unordered_map<Node *, bool> visited;
        dfs(start, visited);
        cout << endl;
    }

    void print()
    {
        if (empty())
        {
            cout << "Graph Is Empty" << endl;
            return;
        }
        for (auto i : nodes)
        {
            cout << i.first << " -> ";
            for (auto j : adjacency_list[i.second])
            {
                cout << j->data << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph = Graph();
    Node *a = graph.create_node("A");
    Node *b = graph.create_node("B");
    Node *c = graph.create_node("C");
    Node *d = graph.create_node("D");
    Node *e = graph.create_node("E");
    Node *f = graph.create_node("F");
    Node *g = graph.create_node("G");
    graph.print();
    graph.create_connection(a, b, DIRECTED);
    graph.create_connection(a, c, DIRECTED);
    graph.create_connection(b, d, DIRECTED);
    graph.create_connection(b, e, DIRECTED);
    graph.create_connection(c, f, DIRECTED);
    graph.create_connection(e, f, DIRECTED);
    graph.create_connection(d, g, DIRECTED);
    graph.create_connection(f, g, DIRECTED);
    graph.print();
    graph.bfs(a);
    graph.dfs(a);
    return 0;
}
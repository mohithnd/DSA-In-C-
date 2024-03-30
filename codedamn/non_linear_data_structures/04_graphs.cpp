#include <iostream>
#include <map>
#include <vector>
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
    map<Node *, vector<Node *>> adjacency_list;
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

    void print()
    {
        if (adjacency_list.empty())
        {
            cout << "Graph Is Empty" << endl;
            return;
        }
        for (auto i : adjacency_list)
        {
            cout << i.first->data << " -> ";
            for (auto j : i.second)
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
    graph.print();
    graph.create_connection(a, b, DIRECTED);
    graph.create_connection(a, c, UNDIRECTED);
    graph.print();
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

void print_1(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue Is Empty" << endl;
        return;
    }
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void print_2(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue Is Empty" << endl;
        return;
    }
    vector<int> arr;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        cout << ele << " ";
        arr.push_back(ele);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
    }
    cout << endl;
}

void print_3(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue Is Empty" << endl;
        return;
    }
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(3);
    q.push(5);
    // print_1(q);
    // print_1(q);
    // print_2(q);
    // print_2(q);
    print_3(q);
    print_3(q);
    return 0;
}
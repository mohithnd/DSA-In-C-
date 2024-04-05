#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

void print(queue<int> q)
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

void reverse_using_recursion(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int ele = q.front();
    q.pop();
    reverse_using_recursion(q);
    q.push(ele);
}

vector<int> first_negative_integer_in_every_window_of_size_k(vector<int> arr, int k)
{
    vector<int> ans;
    return ans;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    vector<int> ans = first_negative_integer_in_every_window_of_size_k(arr, 2);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
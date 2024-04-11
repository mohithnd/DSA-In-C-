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
    queue<int> q;
    for (int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }
    int i = k - 1;
    while (i < arr.size())
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
        if (q.empty() == false)
        {
            if (q.front() <= (i - k))
            {
                q.pop();
            }
        }
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[q.front()]);
        }
        i++;
    }
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
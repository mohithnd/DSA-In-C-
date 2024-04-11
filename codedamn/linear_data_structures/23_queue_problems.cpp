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

void reverse_first_k_elements_solve(queue<int> &q, int k)
{
    if (q.empty() || k <= 0)
    {
        return;
    }
    int data = q.front();
    q.pop();
    reverse_first_k_elements_solve(q, k - 1);
    q.push(data);
    return;
}

queue<int> reverse_first_k_elements(queue<int> q, int k)
{
    reverse_first_k_elements_solve(q, k);
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    print(q);
    q = reverse_first_k_elements(q, 3);
    print(q);
    return 0;
}
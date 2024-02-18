#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int helper_1(queue<int> q)
{
    int ans = 0;
    while (!q.empty())
    {
        if (q.front() < 0)
        {
            ans = q.front();
            break;
        }
        q.pop();
    }
    return ans;
}

void print_first_negative_1(vector<int> arr, int k)
{
    queue<int> q;
    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }
    for (int i = k - 1; i < arr.size(); i++)
    {
        q.push(arr[i]);
        cout << helper_1(q) << " ";
        q.pop();
    }
    cout << endl;
}

void print_first_negative_2(vector<int> arr, int k)
{
    queue<int> q;
    for (int i = 0; i < k - 1; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }
    for (int i = k - 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            if (q.front() <= (i - k))
            {
                q.pop();
            }
            if (q.empty())
            {
                cout << 0 << " ";
            }
            else
            {
                cout << arr[q.front()] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    print_first_negative_1(arr, k);
    print_first_negative_2(arr, k);
    return 0;
}
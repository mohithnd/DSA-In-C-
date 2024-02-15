#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int time_needed_1(vector<int> arr, int k)
{
    int ans = 0;
    queue<int> q;
    for (int i = 0; i < arr.size(); i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        arr[front]--;
        ans++;
        if (arr[front] == 0 && front == k)
        {
            break;
        }
        if (arr[front] != 0)
        {
            q.push(front);
        }
    }
    return ans;
}

int time_needed_2(vector<int> arr, int k)
{
    int ans = 0;
    queue<int> q;
    for (int i = 0; i <= k; i++)
    {
        ans += min(arr[i], arr[k]);
    }
    for (int i = k + 1; i < arr.size(); i++)
    {
        ans += min(arr[i], arr[k] - 1);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 2, 3, 7};
    cout << time_needed_1(arr, 2) << endl;
    cout << time_needed_2(arr, 2) << endl;
    return 0;
}
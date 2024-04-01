#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int sum_1(vector<int> arr, int k1, int k2)
{
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = k1; i < k2 - 1; i++)
    {
        ans += arr[i];
    }
    return ans;
}

int sum_2(vector<int> arr, int k1, int k2)
{
    int ans = 0;
    priority_queue<int> q;
    for (int i = 0; i < k2; i++)
    {
        q.push(arr[i]);
    }
    for (int i = k2; i < arr.size(); i++)
    {
        if (arr[i] < q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    q.pop();
    for (int i = 0; i < (k2 - k1 - 1); i++)
    {
        ans += q.top();
        q.pop();
    }
    return ans;
}

int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    cout << sum_1(arr, 3, 6) << endl;
    cout << sum_2(arr, 3, 6) << endl;
    return 0;
}
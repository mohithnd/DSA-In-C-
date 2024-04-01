#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int kth_largest_1(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k];
}

int kth_largest_2(vector<int> arr, int k)
{
    priority_queue<int> q;
    for (int i : arr)
    {
        q.push(i);
    }
    int ele;
    for (int i = 0; i < k; i++)
    {
        ele = q.top();
        q.pop();
    }
    return ele;
}

int kth_largest_3(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] > q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}

int main()
{
    vector<int> arr = {10, 3, 7, 4, 8, 9, 2, 6};
    cout << kth_largest_1(arr, 4) << endl;
    cout << kth_largest_2(arr, 4) << endl;
    cout << kth_largest_3(arr, 4) << endl;
    return 0;
}
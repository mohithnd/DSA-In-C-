#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void sliding_window_maximum_1(vector<int> arr, int k)
{
    int n = arr.size();
    for (int i = 0; i <= n - k; i++)
    {
        int ans = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            ans = max(ans, arr[j]);
        }
        cout << ans << " ";
    }
    cout << endl;
}

void sliding_window_maximum_2(vector<int> arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    for (int i = 0; i < k - 1; i++)
    {
        while (!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k - 1; i < n; i++)
    {
        while (!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.back() <= (i - k))
        {
            dq.pop_front();
        }
        cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    sliding_window_maximum_1(arr, 4);
    sliding_window_maximum_2(arr, 4);
    return 0;
}
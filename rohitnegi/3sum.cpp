#include <iostream>
#include <algorithm>
using namespace std;

void solve1(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    cout << arr[i] << " , " << arr[j] << " , " << arr[k] << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << " , " << -1 << " , " << -1 << endl;
}

void solve2(int *arr, int n, int target)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = target - arr[i] - arr[j];
            int s = j + 1;
            int e = n - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (arr[mid] == x)
                {
                    cout << arr[i] << " , " << arr[j] << " , " << arr[mid] << endl;
                    return;
                }
                if (x < arr[mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
        }
    }
    cout << -1 << " , " << -1 << " , " << -1 << endl;
}

void solve3(int *arr, int n, int target)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int newTarget = target - arr[i];
        int s = i + 1;
        int e = n - 1;
        while (s < e)
        {
            if (arr[s] + arr[e] == newTarget)
            {
                cout << arr[i] << " , " << arr[s] << " , " << arr[e] << endl;
                return;
            }
            if (arr[s] + arr[e] < newTarget)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
    }
    cout << -1 << " , " << -1 << " , " << -1 << endl;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(int);
    int target = 24;
    solve1(arr, n, target);
    solve2(arr, n, target);
    solve3(arr, n, target);
    return 0;
}
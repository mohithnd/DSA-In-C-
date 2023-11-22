#include <iostream>
#include <algorithm>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve1(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << arr[i] << " , " << arr[j] << endl;
                return;
            }
        }
    }
    cout << -1 << " , " << -1 << endl;
}

void solve2(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int x = target - arr[i];
        int s = i + 1;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] == x)
            {
                cout << arr[i] << " , " << arr[mid] << endl;
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
    cout << -1 << " , " << -1 << endl;
}

void solve3(int *arr, int n, int target)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            cout << arr[i] << " , " << arr[j] << endl;
            return;
        }
        if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << -1 << " , " << -1 << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 18, 25};
    int n = sizeof(arr) / sizeof(int);
    int target = 10;
    solve1(arr, n, target);
    solve2(arr, n, target);
    solve3(arr, n, target);
    return 0;
}
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

void solve1(int *arr, int n)
{
    sort(arr, arr + n);
}

void solve2(int *arr, int n)
{
    int one = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    for (int i = 0; i < zero; i++)
    {
        arr[i] = 0;
    }
    for (int i = zero; i < n; i++)
    {
        arr[i] = 1;
    }
}

void solve3(int *arr, int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        else if (arr[j] == 1)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 1, 0, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    // solve1(arr, n);
    // solve2(arr, n);
    solve3(arr, n);
    print(arr, n);
    return 0;
}
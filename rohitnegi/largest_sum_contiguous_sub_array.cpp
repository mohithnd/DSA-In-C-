#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(int *arr, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve1(int *arr, int n)
{
    int max = INT_MIN;
    int ansS = -1;
    int ansE = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = j; k < n && k < j + i; k++)
            {
                sum += arr[k];
            }
            if (sum > max)
            {
                max = sum;
                ansS = j;
                ansE = j + i - 1;
            }
        }
    }
    print(arr, ansS, ansE);
    cout << max << endl
         << endl;
}

void solve2(int *arr, int n)
{
    int max = INT_MIN;
    int anss = -1;
    int anse = -1;
    int *pref = new int[n];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = j;
            int e = j + i - 1;
            if (e >= n)
            {
                break;
            }
            int sum = 0;
            if (s == 0)
            {
                sum = pref[e];
            }
            else
            {
                sum = pref[e] - pref[s - 1];
            }
            if (sum > max)
            {
                max = sum;
                anss = j;
                anse = j + i - 1;
            }
        }
    }
    print(arr, anss, anse);
    cout << max << endl
         << endl;
}

void solve3(int *arr, int n)
{
    int max = INT_MIN;
    int anss = -1;
    int anse = -1;
    int *pref = new int[n];
    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            int s = i;
            int e = j;
            if (s == 0)
            {
                sum = pref[e];
            }
            else
            {
                sum = pref[e] - pref[s - 1];
            }
            if (sum > max)
            {
                max = sum;
                anss = s;
                anse = e;
            }
        }
    }
    print(arr, anss, anse);
    cout << max << endl
         << endl;
}

int main()
{
    int arr[] = {3, 4, -5, 8, -12, 7, 6, -2};
    int n = sizeof(arr) / sizeof(int);
    solve1(arr, n);
    solve2(arr, n);
    solve3(arr, n);
    return 0;
}
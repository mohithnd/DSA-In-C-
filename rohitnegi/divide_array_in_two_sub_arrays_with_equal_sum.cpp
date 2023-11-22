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
    for (int i = 0; i < n - 1; i++)
    {
        int s = 0;
        int e = 0;
        for (int j = 0; j <= i; j++)
        {
            s += arr[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            e += arr[j];
        }
        if (s == e)
        {
            print(arr, 0, i);
            print(arr, i + 1, n - 1);
            cout << endl;
            return;
        }
    }
    cout << "Not Possible" << endl;
}

void solve2(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int *pref = new int[n];
    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
        if (pref[i] == sum - pref[i])
        {

            print(arr, 0, i);
            print(arr, i + 1, n - 1);
            cout << endl;
            return;
        }
    }
    cout << "Not Possible" << endl
         << endl;
}

int main()
{
    int arr[] = {3, 4, -2, 5, 8, 20, -10, 8};
    int n = sizeof(arr) / sizeof(int);
    solve1(arr, n);
    solve2(arr, n);
    return 0;
}
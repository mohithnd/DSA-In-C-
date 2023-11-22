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

int *prefix(int *arr, int n)
{
    int *ans = new int[n];
    ans[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + arr[i];
    }
    return ans;
}

int *suffix(int *arr, int n)
{
    int *ans = new int[n];
    ans[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = ans[i + 1] + arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {6, 4, 5, -3, 2, 8};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    int *pref = prefix(arr, n);
    print(pref, n);
    int *suff = suffix(arr, n);
    print(suff, n);
    return 0;
}
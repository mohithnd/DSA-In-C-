#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    return ans;
}

int *method2(int *arr, int n)
{
    // O(n*logn) time complexity
    // O(n) space complexity
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = arr[i];
    }
    sort(arr, arr + n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
        {
            m[arr[i]] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = m[ans[i]];
    }
    return ans;
}

int *method3(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    int *ans = new int[n];
    int temp[101] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    for (int i = 1; i < 101; i++)
    {
        temp[i] += temp[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = temp[arr[i] - 1];
        }
    }
    return ans;
}

int main()
{
    int arr[] = {8, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // int *ans = method1(arr, n);
    // int *ans = method2(arr, n);
    int *ans = method3(arr, n);
    print(ans, n);
    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt & 1 == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

int method2(int *arr, int n)
{
    // O(n) time complexity
    // O(n) space complexity
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto i : m)
    {
        if (i.second & 1 == 1)
        {
            return i.first;
        }
    }
    return -1;
}

int method3(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    if (ans != -1)
    {
        return ans;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 3, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << method1(arr, n) << endl;
    cout << method2(arr, n) << endl;
    cout << method3(arr, n) << endl;
    return 0;
}
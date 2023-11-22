#include <iostream>
using namespace std;

int method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        bool found = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int method2(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    // overflow for large arrays
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }
    int ans = n * (n + 1) / 2 - sum;
    return ans;
}

int method3(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    // overflow problem resolved
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans ^ i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[10] = {2, 4, 6, 8, 1, 5, 7, 9, 10};
    cout << method1(arr, 10) << endl;
    cout << method2(arr, 10) << endl;
    cout << method3(arr, 10) << endl;
    return 0;
}
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

void rotate_once(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    int last = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

void method1(int *arr, int n, int k)
{
    // O(n*k) time complexity
    // O(1) space complexity
    for (int i = 0; i < k; i++)
    {
        rotate_once(arr, n);
    }
}

void method2(int *arr, int n, int k)
{
    // O(n+k) time complexity
    // O(k) space complexity
    int *ans = new int[k];
    int j = 0;
    for (int i = n - k; i < n; i++)
    {
        ans[j] = arr[i];
        j++;
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = ans[i];
    }
    delete[] ans;
}

void reverse(int *arr, int s, int e)
{
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void method3(int *arr, int n, int k)
{
    // O(n) time complexity
    // O(1) space complexity
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - k - 1);
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // method1(arr, n, 3);
    // print(arr, n);
    // method2(arr, n, 3);
    // print(arr, n);
    method3(arr, n, 3);
    print(arr, n);
    return 0;
}
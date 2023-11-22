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

void method1(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c0++;
        }
        else if (arr[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    for (int i = 0; i < c0; i++)
    {
        arr[i] = 0;
    }
    for (int i = c0; i < c0 + c1; i++)
    {
        arr[i] = 1;
    }
    for (int i = c0 + c1; i < n; i++)
    {
        arr[i] = 2;
    }
}

void method2(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    // dutch national flag algo - only one pass required
    int l = 0;
    int h = n - 1;
    int c = 0;
    while (c < h)
    {
        if (arr[c] == 0)
        {
            swap(arr[c], arr[l]);
            l++;
            c++;
        }
        else if (arr[c] == 1)
        {
            c++;
        }
        else
        {
            swap(arr[c], arr[h]);
            h--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // method1(arr, n);
    method2(arr, n);
    print(arr, n);
    return 0;
}
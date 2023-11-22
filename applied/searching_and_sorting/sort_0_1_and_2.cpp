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

void method1(int *arr, int n)
{
    sort(arr, arr + n);
}

void method2(int *arr, int n)
{
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
    int i = 0;
    while (i < c0)
    {
        arr[i] = 0;
        i++;
    }
    while (i < (c0 + c1))
    {
        arr[i] = 1;
        i++;
    }
    while (i < (c0 + c1 + c2))
    {
        arr[i] = 2;
        i++;
    }
}

void method3(int *arr, int n)
{
    int c = 0;
    int l = 0;
    int h = n - 1;
    while (c <= h)
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
    // int arr[] = {0, 1, 0, 1, 2, 1, 2, 1};
    // int arr[] = {2, 0, 2, 1, 1, 0};
    int arr[] = {1, 0, 2};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // method1(arr, n);
    // method2(arr, n);
    method3(arr, n);
    print(arr, n);
    return 0;
}
#include <iostream>
using namespace std;

int max(int *arr, int n)
{
    if (n < 0)
    {
        return INT_MIN;
    }
    int temp = max(arr, n - 1);
    return temp > arr[n] ? temp : arr[n];
}

int min(int *arr, int n)
{
    if (n < 0)
    {
        return INT_MAX;
    }
    int temp = min(arr, n - 1);
    return temp < arr[n] ? temp : arr[n];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << max(arr, n - 1) << endl;
    cout << min(arr, n - 1) << endl;
    return 0;
}
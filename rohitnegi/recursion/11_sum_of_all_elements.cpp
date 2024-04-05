#include <iostream>
using namespace std;

int sum_1(int *arr, int n, int i)
{
    if (i >= n)
    {
        return 0;
    }
    return arr[i] + sum_1(arr, n, i + 1);
}

int sum_2(int *arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    return arr[n] + sum_2(arr, n - 1);
}

int main()
{
    int arr[] = {3, 4, 5, 8, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << sum_1(arr, n, 0) << endl;
    cout << sum_2(arr, n - 1) << endl;
    return 0;
}
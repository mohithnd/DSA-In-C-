#include <iostream>
using namespace std;

int min_1(int *arr, int n, int i)
{
    if (i == n - 1)
    {
        return arr[i];
    }
    return min(arr[i], min_1(arr, n, i + 1));
}

int min_2(int *arr, int n)
{
    if (n == 0)
    {
        return arr[n];
    }
    return min(arr[n], min_2(arr, n - 1));
}

int main()
{
    int arr[] = {7, 2, 4, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << min_1(arr, n, 0) << endl;
    cout << min_2(arr, n - 1) << endl;
    return 0;
}
#include <iostream>
using namespace std;

void print_2(int *arr, int n)
{
    if (n < 0)
    {
        return;
    }
    print_2(arr, n - 1);
    cout << arr[n] << " ";
}

void print_1(int *arr, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    cout << arr[i] << " ";
    print_1(arr, n, i + 1);
}

int main()
{
    int arr[] = {3, 7, 6, 2, 8};
    int n = sizeof(arr) / sizeof(int);
    print_1(arr, n, 0);
    cout << endl;
    print_2(arr, n - 1);
    return 0;
}
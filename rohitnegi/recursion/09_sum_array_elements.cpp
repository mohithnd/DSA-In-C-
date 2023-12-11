#include <iostream>
using namespace std;

int sum(int *arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    return arr[n] + sum(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << sum(arr, n - 1) << endl;
    return 0;
}
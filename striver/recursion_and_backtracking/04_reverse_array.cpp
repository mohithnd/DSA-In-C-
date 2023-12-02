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

void reverse(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    swap(arr[s], arr[e]);
    reverse(arr, s + 1, e - 1);
}

void reverse2(int *arr, int i, int n)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - 1 - i]);
    reverse2(arr, i + 1, n);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    print(arr, 5);
    reverse(arr, 0, 4);
    print(arr, 5);
    reverse2(arr, 0, 5);
    print(arr, 5);
    return 0;
}
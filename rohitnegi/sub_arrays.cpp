#include <iostream>
using namespace std;

void print(int *arr, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void subArrays(int *arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j + i - 1 < n)
            {
                print(arr, j, j + i - 1);
            }
        }
    }
}

int main()
{
    int arr[] = {4, 3, 7, 2};
    int n = sizeof(arr) / sizeof(int);
    print(arr, 0, n - 1);
    subArrays(arr, n);
    return 0;
}
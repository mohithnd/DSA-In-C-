#include <iostream>
#include <vector>
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

bool method1(int *arr, int n, int sum)
{
    // O(n) time complexity
    // O(1) space complexity
    int pivot = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            pivot = i;
        }
    }
    int l = pivot + 1;
    int r = pivot;
    while (l != r)
    {
        if (arr[l] + arr[r] == sum)
        {
            return true;
        }
        else if (arr[l] + arr[r] > sum)
        {
            r = (r - 1 + n) % n;
        }
        else
        {
            l = (l + 1) % n;
        }
    }
    return false;
}

int main()
{
    int arr[] = {11, 15, 26, 38, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int sum = 20;
    cout << method1(arr, n, sum) << endl;
    return 0;
}
#include <iostream>
using namespace std;

int binary_search_iterative(int arr[], int n, int target)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(int arr[], int s, int e, int target)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (target < arr[mid])
    {
        return binary_search_recursive(arr, s, mid - 1, target);
    }
    else
    {
        return binary_search_recursive(arr, mid + 1, e, target);
    }
}

int main()
{
    int arr[] = {3, 4, 6, 7, 9, 12, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binary_search_iterative(arr, n, 13) << endl;
    cout << binary_search_iterative(arr, n, 16) << endl;
    cout << binary_search_recursive(arr, 0, n - 1, 13) << endl;
    cout << binary_search_recursive(arr, 0, n - 1, 16) << endl;
    return 0;
}
#include <iostream>
using namespace std;

bool binary_search(int *arr, int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    if (key < arr[mid])
    {
        return binary_search(arr, s, mid - 1, key);
    }
    return binary_search(arr, mid + 1, e, key);
}

int main()
{
    int arr[] = {2, 4, 7, 3, 11, 8, 12};
    int n = sizeof(arr) / sizeof(int);
    cout << binary_search(arr, 0, n - 1, 3) << endl;
    cout << binary_search(arr, 0, n - 1, 30) << endl;
    return 0;
}
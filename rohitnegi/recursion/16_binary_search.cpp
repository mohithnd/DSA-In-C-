#include <iostream>
using namespace std;

bool binary_search(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] > key)
    {
        return binary_search(arr, s, mid - 1, key);
    }
    else
    {
        return binary_search(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << binary_search(arr, 0, n - 1, key) << endl;
    return 0;
}
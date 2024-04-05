#include <iostream>
using namespace std;

bool linear_search(int *arr, int n, int i, int key)
{
    if (i >= n)
    {
        return false;
    }
    if (arr[i] == key)
    {
        return true;
    }
    return linear_search(arr, n, i + 1, key);
}

int main()
{
    int arr[] = {2, 4, 7, 3, 11, 8, 12};
    int n = sizeof(arr) / sizeof(int);
    cout << linear_search(arr, n, 0, 3) << endl;
    cout << linear_search(arr, n, 0, 30) << endl;
    return 0;
}
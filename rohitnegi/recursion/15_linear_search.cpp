#include <iostream>
using namespace std;

bool is_present(int arr[], int i, int n, int key)
{
    if (i >= n)
    {
        return false;
    }
    if (arr[i] == key)
    {
        return true;
    }
    return is_present(arr, i + 1, n, key);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << is_present(arr, 0, n, key) << endl;
    return 0;
}
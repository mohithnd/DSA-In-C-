#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int occurence(int *arr, int n, int key)
{
    int ans = lastOcc(arr, n, key) - firstOcc(arr, n, key) + 1;
    return ans;
}

int main()
{
    int arr[] = {2, 4, 4, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int key = 4;
    cout << occurence(arr, n, key) << endl;
    return 0;
}
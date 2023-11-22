#include <iostream>
using namespace std;

int is_present(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] >= arr[0])
        {
            if (arr[s] <= key && key < arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid] && key <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int key = 1;
    cout << is_present(arr, n, -10) << endl;
    for (int i : arr)
    {
        cout << is_present(arr, n, i) << endl;
    }
    return 0;
}
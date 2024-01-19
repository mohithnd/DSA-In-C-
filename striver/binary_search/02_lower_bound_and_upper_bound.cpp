#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (x < arr[mid])
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

int upper_bound(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= x)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {3, 5, 8, 15, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    cout << "Lower bound of " << x << " is: " << lower_bound(arr, n, x) << endl;
    cout << "Upper bound of " << x << " is: " << upper_bound(arr, n, x) << endl;
    return 0;
}
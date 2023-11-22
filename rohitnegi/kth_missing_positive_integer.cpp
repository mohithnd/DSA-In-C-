#include <iostream>
using namespace std;

int kth_missing_number(int *arr, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if ((arr[mid] - mid - 1) >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans + k;
}

int main()
{
    int arr[] = {2, 3, 4, 7, 11, 12};
    int n = sizeof(arr) / sizeof(int);
    int k = 5;
    cout << kth_missing_number(arr, n, k) << endl;
    return 0;
}
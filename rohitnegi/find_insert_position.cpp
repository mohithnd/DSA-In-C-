#include <iostream>
using namespace std;

int insert_position(int *arr, int n, int target)
{
    int ans = n;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target <= arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 6, 8, 10, 14, 16, 18};
    int n = sizeof(arr) / sizeof(int);
    int target = 9;
    cout << insert_position(arr, n, target) << endl;
    return 0;
}
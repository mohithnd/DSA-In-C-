#include <iostream>
using namespace std;

int insert_position(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    cout << insert_position(arr, n, target) << endl;
    return 0;
}
#include <iostream>
using namespace std;

int peak_index(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    int ans;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 8, 5};
    int n = sizeof(arr) / sizeof(int);
    cout << peak_index(arr, n) << endl;
    return 0;
}
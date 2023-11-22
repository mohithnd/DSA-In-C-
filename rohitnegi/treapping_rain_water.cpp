#include <iostream>
using namespace std;

int solve(int *arr, int n)
{
    int *left = new int[n];
    int temp = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        temp = max(temp, arr[i]);
        left[i] = temp;
    }
    int *right = new int[n];
    temp = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        temp = max(temp, arr[i]);
        right[i] = temp;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = left[i];
        int rightMax = right[i];
        int support = min(leftMax, rightMax);
        int diff = support - arr[i];
        if (diff >= 0)
        {
            ans = ans + diff;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {4, 2, 0, 5, 2, 6, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << solve(arr, n) << endl;
    return 0;
}
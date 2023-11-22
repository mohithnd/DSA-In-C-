#include <iostream>
#include <algorithm>
using namespace std;

int method1(int *arr, int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

int method2(int *arr, int n, int k)
{
    int ans;
    for (int i = 0; i < n; i++)
    {
        int min = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                min++;
            }
        }
        if (min == (k - 1))
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int method3(int *arr, int n, int k)
{
}

int main()
{
    int arr[] = {13, 12, 11, 14, 15, 17, 18, 20, 19, 16};
    int n = sizeof(arr) / sizeof(int);
    cout << method1(arr, n, 4) << endl;
    cout << method2(arr, n, 4) << endl;
    return 0;
}
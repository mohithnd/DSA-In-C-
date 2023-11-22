#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                ans++;
            }
        }
    }
    return ans;
}

int merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }
    int i = 0;
    int j = 0;
    k = s;
    int ans = 0;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
            ans += mid - i + 1;
        }
    }
    while (i < len1)
    {
        arr[k++] = first[i++];
    }
    while (j < len2)
    {
        arr[k++] = second[j++];
    }
    delete[] first;
    delete[] second;
    return ans;
}

int merge_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int ans = 0;
    int mid = s + (e - s) / 2;
    ans += merge_sort(arr, s, mid);
    ans += merge_sort(arr, mid + 1, e);
    ans += merge(arr, s, e);
    return ans;
}

int method2(int *arr, int n)
{
    // O(n*logn) time complexity
    // O(n) space complexity
    int ans = 0;
    ans += merge_sort(arr, 0, n - 1);
    return ans;
}

int main()
{
    int arr[] = {2, 5, 1, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    cout << method1(arr, n) << endl;
    cout << method2(arr, n) << endl;
    return 0;
}
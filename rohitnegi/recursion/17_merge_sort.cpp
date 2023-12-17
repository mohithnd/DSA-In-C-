#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    int left[len1], right[len2];
    for (int i = 0; i < len2; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = left[i++];
    }
    while (j < len2)
    {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arr[] = {6, 4, 7, 2, 9, 8, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    merge_sort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
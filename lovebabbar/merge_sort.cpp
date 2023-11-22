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

void merge(int *arr, int s, int e)
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
    k = s;
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
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
}

void merge_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    merge_sort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
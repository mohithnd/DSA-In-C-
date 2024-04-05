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

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[i + s];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int main_array_index = s;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            arr[main_array_index++] = first[i++];
        }
        else
        {
            arr[main_array_index++] = second[j++];
        }
    }
    while (i < len1)
    {
        arr[main_array_index++] = first[i++];
    }
    while (j < len2)
    {
        arr[main_array_index++] = second[j++];
    }
    delete[] first;
    delete[] second;
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
    int arr[] = {6, 4, 7, 2, 9, 8, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    merge_sort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
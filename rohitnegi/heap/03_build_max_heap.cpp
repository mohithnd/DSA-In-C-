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

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (i != largest)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void build_max_heap(int *arr, int n)
{
    // Step Down
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    build_max_heap(arr, n);
    print(arr, n);
    return 0;
}
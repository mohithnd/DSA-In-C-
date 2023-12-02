#include <iostream>
#include <vector>
using namespace std;

int get_partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int partition_index = get_partition(arr, low, high);
    quick_sort(arr, low, partition_index - 1);
    quick_sort(arr, partition_index + 1, high);
}

int main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = arr.size();
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int low = s;
    int high = mid + 1;
    vector<int> temp;
    while (low <= mid && high <= e)
    {
        if (arr[low] <= arr[high])
        {
            temp.push_back(arr[low]);
            low++;
        }
        else
        {
            temp.push_back(arr[high]);
            high++;
        }
    }
    while (low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while (high <= e)
    {
        temp.push_back(arr[high]);
        high++;
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
}

void merger_sort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    merger_sort(arr, s, mid);
    merger_sort(arr, mid + 1, e);
    merge(arr, s, e);
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
    merger_sort(arr, 0, n - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
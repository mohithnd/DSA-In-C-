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
void sort_array(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    sort_array(arr, n - 1);
}
int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    sort_array(arr, n);
    print(arr, n);
    return 0;
}
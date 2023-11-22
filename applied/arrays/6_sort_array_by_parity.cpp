#include <iostream>
#include <vector>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void method1(int *arr, int n)
{
    // O(n) time complexity
    // O(n) space complexity
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }
    int i = 0;
    for (int data : even)
    {
        arr[i++] = data;
    }
    for (int data : odd)
    {
        arr[i++] = data;
    }
}

void method2(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] % 2 == 1 && arr[j] % 2 == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] % 2 == 0)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // method1(arr, n);
    method2(arr, n);
    print(arr, n);
    return 0;
}
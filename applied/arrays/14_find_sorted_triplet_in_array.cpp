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

void method1(int *arr, int n)
{
    // O(n^3) time complexity
    // O(1) space complexity
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                continue;
            }
            for (int k = j + 1; k < n; k++)
            {
                if (arr[k] < arr[j])
                {
                    continue;
                }
                cout << arr[i] << " , " << arr[j] << " , " << arr[k] << endl;
                return;
            }
        }
    }
    cout << "Cannot Find Such Triplet" << endl;
}

void method2(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    for (int i = 1; i < n - 1; i++)
    {
        int j = 0;
        while (j < i)
        {
            if (arr[j] < arr[i])
            {
                break;
            }
            j++;
        }
        int k = i + 1;
        while (k < n)
        {
            if (arr[k] > arr[i])
            {
                break;
            }
            k++;
        }
        if (j < i && k < n)
        {
            cout << arr[j] << " , " << arr[i] << " , " << arr[k] << endl;
            return;
        }
    }
    cout << "Cannot Find Such Triplet" << endl;
}

void method3(int *arr, int n)
{
}

int main()
{
    int arr[] = {5, 4, 3, 7, 6, 1, 9};
    int n = sizeof(arr) / sizeof(int);
    method1(arr, n);
    method2(arr, n);
    method3(arr, n);
    return 0;
}
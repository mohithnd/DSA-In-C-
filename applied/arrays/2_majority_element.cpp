#include <iostream>
#include <map>
using namespace std;

int method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                temp++;
            }
        }
        if (temp > (n / 2))
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int method2(int *arr, int n)
{
    // O(n) time complexity
    // O(n) space complexity
    int ans = -1;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto itr : m)
    {
        if (itr.second > (n / 2))
        {
            ans = itr.first;
            break;
        }
    }
    return ans;
}

int method3(int *arr, int n)
{
    // Boyer-Moore Algo
    // O(n) time complexity
    // O(1) space complexity
    int ans = -1;
    int counter = 1;
    int majority = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (counter == 0)
        {
            majority = arr[i];
            counter = 1;
        }
        else if (majority == arr[i])
        {
            counter++;
        }
        else
        {
            counter--;
        }
    }
    counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == majority)
        {
            counter++;
        }
    }
    if (counter > (n / 2))
    {
        ans = majority;
    }
    return ans;
}

int main()
{
    // int arr[] = {2, 8, 7, 2, 2, 1, 2};
    // int arr[] = {2, 8, 7, 2, 1};
    int arr[] = {3, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    cout << method1(arr, n) << endl;
    cout << method2(arr, n) << endl;
    cout << method3(arr, n) << endl;
    return 0;
}
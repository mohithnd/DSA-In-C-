#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> method2(int *arr, int n)
{
    // O(n) time complexity
    // O(1) space complexity
    vector<int> ans;
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < max)
        {
        }
        else
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int arr[] = {8, 4, 2, 3, 1, 5, 4, 2};
    // int arr[] = {10, 6, 3, 1, 7, 9};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    print_vector(method1(arr, n));
    print_vector(method2(arr, n));
    return 0;
}
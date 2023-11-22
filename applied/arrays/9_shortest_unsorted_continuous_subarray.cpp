#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int method1(int *arr, int n)
{
    // O(n^2) time complexity
    // O(1) space complexity
    int s = n;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                s = min(s, i);
                e = max(e, j);
            }
        }
    }
    int ans = e - s + 1;
    if (ans >= 0)
    {
        return ans;
    }
    return 0;
}

int method2(int *arr, int n)
{
    // O(n*logn) time complexity
    // O(n) space complexity
    int *other = new int[n];
    for (int i = 0; i < n; i++)
    {
        other[i] = arr[i];
    }
    int s = n;
    int e = 0;
    sort(other, other + n);
    for (int i = 0; i < n; i++)
    {
        if (other[i] != arr[i])
        {
            s = min(s, i);
            e = max(e, i);
        }
    }
    int ans = e - s + 1;
    if (ans >= 0)
    {
        return ans;
    }
    return 0;
}

int method3(int *arr, int n)
{
    // O(n) time complexity
    // O(n) space complexity
    stack<int> st;
    int s = n;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (arr[i] < arr[st.top()])
            {
                s = min(s, st.top());
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        st.pop();
    }
    int e = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (arr[i] > arr[st.top()])
            {
                e = max(e, st.top());
                st.pop();
            }
            st.push(i);
        }
    }
    int ans = e - s + 1;
    if (ans >= 0)
    {
        return ans;
    }
    return 0;
}

int main()
{
    int arr[] = {2, 6, 4, 8, 10, 9, 15};
    // int arr[] = {1, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(int);
    // cout << method1(arr, n) << endl;
    // cout << method2(arr, n) << endl;
    cout << method3(arr, n) << endl;
    return 0;
}
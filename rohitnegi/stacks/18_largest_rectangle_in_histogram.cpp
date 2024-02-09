#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largest_area_1(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int h = arr[i];
        int w = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                break;
            }
            w++;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                break;
            }
            w++;
        }
        int area = h * w;
        ans = max(ans, area);
    }
    return ans;
}

int largest_area_2(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    vector<int> right(n, -1);
    vector<int> left(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int h = arr[i];
        int w = 1;
        if (left[i] == -1)
        {
            w += i;
        }
        else
        {
            w += i - left[i] - 1;
        }
        if (right[i] == -1)
        {
            w += n - 1 - i;
        }
        else
        {
            w += right[i] - i - 1;
        }
        ans = max(ans, h * w);
    }
    return ans;
}

int largest_area_3(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int index = st.top();
            st.pop();
            if (!st.empty())
            {
                int area = arr[index] * (i - st.top() - 1);
                ans = max(ans, area);
            }
            else
            {
                int area = arr[index] * i;
                ans = max(ans, area);
            }
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int index = st.top();
        st.pop();
        if (!st.empty())
        {
            int area = arr[index] * (n - 1 - st.top());
            ans = max(ans, area);
        }
        else
        {
            int area = arr[index] * n;
            ans = max(ans, area);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largest_area_1(arr) << endl;
    cout << largest_area_2(arr) << endl;
    cout << largest_area_3(arr) << endl;
    return 0;
}
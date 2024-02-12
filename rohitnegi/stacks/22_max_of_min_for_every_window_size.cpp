#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> max_of_min_of_for_every_window_1(vector<int> arr)
{
    // O(n^3)
    int n = arr.size();
    vector<int> ans(n, INT_MIN);
    for (int win = 1; win <= n; win++)
    {
        int i = 0;
        int j = win - 1;
        while (j < n)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                mini = min(mini, arr[k]);
            }
            ans[win - 1] = max(ans[win - 1], mini);
            i++;
            j++;
        }
    }
    return ans;
}

vector<int> max_of_min_of_for_every_window_2(vector<int> arr)
{
    // O(n^2)
    int n = arr.size();
    vector<int> ans(n, INT_MIN);
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            int win = j - i + 1;
            ans[win - 1] = max(ans[win - 1], mini);
        }
    }
    return ans;
}

vector<int> create_nsr(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> create_nsl(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> max_of_min_of_for_every_window_3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, INT_MIN);
    vector<int> nsr = create_nsr(arr);
    vector<int> nsl = create_nsl(arr);
    for (int i = 0; i < n; i++)
    {
        int w = 1;
        int left = nsl[i];
        if (left == -1)
        {
            w += i;
        }
        else
        {
            w += i - left - 1;
        }
        int right = nsr[i];
        if (right == -1)
        {
            w += n - 1 - i;
        }
        else
        {
            w += right - i - 1;
        }
        for (int win = 0; win < w; win++)
        {
            ans[win] = max(ans[win], arr[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    print(max_of_min_of_for_every_window_1(arr));
    print(max_of_min_of_for_every_window_2(arr));
    print(max_of_min_of_for_every_window_3(arr));
    return 0;
}
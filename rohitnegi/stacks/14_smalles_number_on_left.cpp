#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> create_sel_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> create_sel_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> create_sel_3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans[i] = arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 13, 11, 5, 9, 7, 8, 6};
    print(arr);
    vector<int> sel = create_sel_1(arr);
    print(sel);
    sel = create_sel_2(arr);
    print(sel);
    sel = create_sel_3(arr);
    print(sel);
    return 0;
}
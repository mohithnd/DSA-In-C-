#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> create_nse_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
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

vector<int> create_nse_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
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

vector<int> create_nse_3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty() == false)
        {
            ans[i] = arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {7, 9, 12, 10, 14, 8, 3, 6, 9};
    print(arr);
    vector<int> nse = create_nse_1(arr);
    print(nse);
    nse = create_nse_2(arr);
    print(nse);
    nse = create_nse_3(arr);
    print(nse);
    return 0;
}
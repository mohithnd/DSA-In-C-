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

vector<int> create_stock_span_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
            ans[i]++;
        }
    }
    return ans;
}

vector<int> create_stock_span_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
    return ans;
}

int main()
{
    // vector<int> arr = {100, 80, 55, 70, 60, 75, 85};
    vector<int> arr = {60, 70, 100};
    print(arr);
    vector<int> stock_span = create_stock_span_1(arr);
    print(stock_span);
    stock_span = create_stock_span_2(arr);
    print(stock_span);
    return 0;
}
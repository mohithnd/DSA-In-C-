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

vector<int> create_nge_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> create_nge_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    int i = 0;
    for (int i = 0; i < n; i++)
    {

        while (st.empty() == false && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> create_nge_3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
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
    vector<int> arr = {8, 6, 4, 7, 4, 9, 10, 9, 12};
    print(arr);
    vector<int> nge = create_nge_1(arr);
    print(nge);
    nge = create_nge_2(arr);
    print(nge);
    nge = create_nge_3(arr);
    print(nge);
    return 0;
}
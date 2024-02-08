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
        for (int j = i + 1; j < 2 * n; j++)
        {
            int ind = j % n;
            if (arr[ind] > arr[i])
            {
                ans[i] = arr[ind];
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
    for (int i = 0; i < 2 * n; i++)
    {
        int ind = i % n;
        while (!st.empty() && arr[ind] > arr[st.top()])
        {
            ans[st.top()] = arr[ind];
            st.pop();
        }
        if (i < n)
        {
            st.push(i);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 10, 7, 4, 8, 9, 4};
    print(arr);
    vector<int> nge = create_sel_1(arr);
    print(nge);
    nge = create_sel_2(arr);
    print(nge);
    return 0;
}
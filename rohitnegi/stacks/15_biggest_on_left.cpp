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

vector<int> create_bel_1(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
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

vector<int> create_bel_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> create_bel_3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
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
    vector<int> arr = {10, 4, 2, 20, 40, 12, 30};
    vector<int> arr1 = {10, 20, 30, 40};
    vector<int> arr2 = {40, 30, 20, 10};
    print(arr);
    vector<int> bel = create_bel_1(arr);
    print(bel);
    bel = create_bel_2(arr);
    print(bel);
    bel = create_bel_3(arr);
    print(bel);

    bel = create_bel_1(arr1);
    print(bel);
    bel = create_bel_2(arr1);
    print(bel);
    bel = create_bel_3(arr1);
    print(bel);

    bel = create_bel_1(arr2);
    print(bel);
    bel = create_bel_2(arr2);
    print(bel);
    bel = create_bel_3(arr2);
    print(bel);
    return 0;
}
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

vector<int> next_greater_element_1(vector<int> arr)
{
    // TC - O(n^2)
    // SC - O(1)
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
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

vector<int> next_greater_element_2(vector<int> arr)
{
    // TC - O(n)
    // SC - O(n)
    vector<int> ans(arr.size(), -1);
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.empty() == false && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty() == false)
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    print(arr);
    vector<int> ans;
    ans = next_greater_element_1(arr);
    print(ans);
    ans = next_greater_element_2(arr);
    print(ans);
    return 0;
}
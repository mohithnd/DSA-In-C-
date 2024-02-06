#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void make_beautiful(vector<int> &arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
        }
        else if (arr[i] >= 0)
        {
            if (st.top() < 0)
            {
                st.pop();
            }
            else
            {
                st.push(arr[i]);
            }
        }
        else
        {
            if (st.top() >= 0)
            {
                st.pop();
            }
            else
            {
                st.push(arr[i]);
            }
        }
    }
    arr.clear();
    arr = vector<int>(st.size(), 0);
    int i = st.size() - 1;
    while (!st.empty())
    {
        arr[i] = st.top();
        i--;
        st.pop();
    }
}

int main()
{
    vector<int> arr = {2, 3, 5, -4, 6, -2, -8, 9};
    print(arr);
    make_beautiful(arr);
    print(arr);
    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

stack<int> create(int *arr, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
        }
        else
        {
            if (st.top() < arr[i])
            {
                st.push(st.top());
            }
            else
            {
                st.push(arr[i]);
            }
        }
    }
    return st;
}

int main()
{
    int arr[] = {2, 1, 3, 5, 0, 6};
    int n = sizeof(arr) / sizeof(int);

    stack<int> min_at_top = create(arr, n);

    while (!min_at_top.empty())
    {
        cout << min_at_top.top() << endl;
        min_at_top.pop();
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int manipulate(vector<string> arr)
{
    stack<string> st;
    for (auto i : arr)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (st.top() == i)
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    return st.size();
}

int main()
{
    vector<string> arr = {"ab", "ac", "da", "da", "ac", "db", "ea"};
    cout << manipulate(arr) << endl;
    return 0;
}
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

vector<int> next_greater_element_circular_1(vector<int> arr)
{
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int count = 0; count < 2 * arr.size(); count++)
        {
            int j = (i + 1 + count) % arr.size();
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> next_greater_element_circular_2(vector<int> arr)
{
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<int> ans(arr.size(), -1);
    stack<int> s;
    for (int i = 2 * arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i % arr.size()])
        {
            s.pop();
        }
        if (i < arr.size())
        {
            if (!s.empty())
            {
                ans[i] = s.top();
            }
        }
        s.push(arr[i % arr.size()]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};
    print(arr);
    vector<int> ans;
    ans = next_greater_element_circular_1(arr);
    print(ans);
    ans = next_greater_element_circular_2(arr);
    print(ans);
    return 0;
}
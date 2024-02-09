#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int helper(vector<int> arr)
{
    int ans = 0;
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int index = st.top();
            st.pop();
            int area = 0;
            if (!st.empty())
            {
                area = arr[index] * (i - st.top() - 1);
            }
            else
            {
                area = arr[index] * i;
            }
            ans = max(ans, area);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int index = st.top();
        st.pop();
        int area = 0;
        if (!st.empty())
        {
            area = arr[index] * (n - st.top() - 1);
        }
        else
        {
            area = arr[index] * n;
        }
        ans = max(ans, area);
    }
    return ans;
}

int max_area_1(vector<vector<char>> grid)
{
    int ans = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> arr(cols, 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                arr[j] += 1;
            }
            else
            {
                arr[j] = 0;
            }
        }
        int area = helper(arr);
        ans = max(ans, area);
    }
    return ans;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    cout << max_area_1(grid) << endl;
    return 0;
}
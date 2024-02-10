#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celeb_1(vector<vector<int>> matrix)
{
    int ans = -1;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        bool f1 = false;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                f1 = true;
                break;
            }
        }
        if (f1 == false)
        {
            bool f2 = false;
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                {
                    continue;
                }
                if (matrix[k][i] == 0)
                {
                    f2 = true;
                    break;
                }
            }
            if (f2 == false)
            {
                ans = i;
                break;
            }
        }
    }
    return ans;
}

int celeb_2(vector<vector<int>> matrix)
{
    stack<int> st;
    int n = matrix.size();
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        if (matrix[first][second] && !matrix[second][first])
        {
            st.push(second);
        }
        if (!matrix[first][second] && matrix[second][first])
        {
            st.push(first);
        }
    }
    if (st.empty())
    {
        return -1;
    }
    int ele = st.top();
    st.pop();
    int row = 0;
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        row += matrix[ele][i];
        col += matrix[i][ele];
    }
    if (row == 0 && col == n - 1)
    {
        return ele;
    }
    return -1;
}

int main()
{
    vector<vector<int>> matrix = {
        {{0, 1, 0},
         {0, 0, 0},
         {0, 1, 0}}};
    cout << celeb_1(matrix) << endl;
    cout << celeb_2(matrix) << endl;
    return 0;
}
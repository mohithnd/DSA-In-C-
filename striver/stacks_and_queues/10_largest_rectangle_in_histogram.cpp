#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largest_rectangle_in_histogram_1(vector<int> heights)
{
    // O(n^2) time | O(1) space
    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int h = heights[i];
        int w = 1;
        int j = i - 1;
        while (j >= 0 && heights[j] >= heights[i])
        {
            w++;
            j--;
        }
        j = i + 1;
        while (j < heights.size() && heights[j] >= heights[i])
        {
            w++;
            j++;
        }
        ans = max(ans, h * w);
    }
    return ans;
}

int largest_rectangle_in_histogram_2(vector<int> heights)
{
    // O(5n) time | O(3n) space
    int ans = INT_MIN;
    stack<int> st;
    int n = heights.size();
    vector<int> left_small(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            left_small[i] = st.top() + 1;
        }
        st.push(i);
    }
    vector<int> right_small(n, n - 1);
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            right_small[i] = st.top() - 1;
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int left = left_small[i];
        int right = right_small[i];
        int area = (right - left + 1) * heights[i];
        ans = max(ans, area);
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    cout << largest_rectangle_in_histogram_1(heights) << endl;
    cout << largest_rectangle_in_histogram_2(heights) << endl;
    return 0;
}
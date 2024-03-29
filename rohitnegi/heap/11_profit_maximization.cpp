#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int profit_maximization(vector<int> arr, int k)
{
    priority_queue<int> q;
    for (int i : arr)
    {
        q.push(i);
    }
    int ans = 0;
    while (k--)
    {
        int top = q.top();
        q.pop();
        ans += top;
        top--;
        if (top)
        {
            q.push(top);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {6, 4, 2, 3};
    cout << profit_maximization(arr, 5) << endl;
    return 0;
}
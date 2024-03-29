#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int min_cost_of_ropes(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i : arr)
    {
        q.push(i);
    }
    int ans = 0;
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 3, 2, 6};
    cout << min_cost_of_ropes(arr) << endl;
    return 0;
}
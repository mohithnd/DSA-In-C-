#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int last_stone_weight(vector<int> arr)
{
    priority_queue<int> q;
    for (int i : arr)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int diff = a - b;
        if (diff)
        {
            q.push(diff);
        }
    }
    return q.empty() ? 0 : q.top();
}

int main()
{
    vector<int> arr = {2, 7, 4, 1, 8, 1};
    cout << last_stone_weight(arr) << endl;
    return 0;
}
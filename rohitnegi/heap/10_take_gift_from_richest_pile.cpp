#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int take_gift_from_richest_pile(vector<int> arr, int k)
{
    priority_queue<int> q;
    for (int i : arr)
    {
        q.push(i);
    }
    while (k)
    {
        int a = q.top();
        q.pop();
        a = sqrt(a);
        q.push(a);
        k--;
    }
    int sum = 0;
    while (!q.empty())
    {
        sum += q.top();
        q.pop();
    }
    return sum;
}

int main()
{
    vector<int> arr = {25, 64, 9, 4, 100};
    cout << take_gift_from_richest_pile(arr, 4) << endl;
    return 0;
}
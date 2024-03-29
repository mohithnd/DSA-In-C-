#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maximum_chocolates(int A, vector<int> B)
{
    priority_queue<int> q;
    for (int i = 0; i < B.size(); i++)
    {
        q.push(B[i]);
    }

    long long ans = 0;
    while (A && (!q.empty()))
    {
        ans += q.top();
        if (q.top() / 2)
        {
            q.push(q.top() / 2);
        }
        q.pop();
        A--;
    }
    return ans % 1000000007;
}

int main()
{
    vector<int> arr = {2, 4, 8, 6, 10};
    cout << maximum_chocolates(5, arr) << endl;
    return 0;
}
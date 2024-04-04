#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FindMedian
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    void insertHeap(int &x)
    {
        if (left.empty())
        {
            left.push(x);
            balanceHeaps();
            return;
        }
        if (x > left.top())
        {
            right.push(x);
        }
        else
        {
            left.push(x);
        }
        balanceHeaps();
    }
    void balanceHeaps()
    {
        if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
        else if ((left.size() - right.size()) > 1)
        {
            right.push(left.top());
            left.pop();
        }
    }
    double getMedian()
    {
        if (left.size() > right.size())
        {
            return left.top();
        }
        double ans;
        ans = left.top() + right.top();
        ans = ans / 2;
        return ans;
    }
};

int main()
{
    vector<int> stream = {7, 11, 4, 9, 15, 2, 1, 18};
    return 0;
}
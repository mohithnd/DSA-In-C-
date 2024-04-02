#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> merge_1(vector<int> h1, vector<int> h2)
{
    vector<int> ans;
    priority_queue<int> q;
    for (int i : h1)
    {
        q.push(i);
    }
    for (int i : h2)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}

void heapify(vector<int> &arr, int i)
{
    int largest = i;
    int lci = 2 * largest + 1;
    int rci = 2 * largest + 2;
    if (lci < arr.size() && arr[lci] > arr[largest])
    {
        largest = lci;
    }
    if (rci < arr.size() && arr[rci] > arr[largest])
    {
        largest = rci;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

vector<int> merge_2(vector<int> h1, vector<int> h2)
{
    vector<int> ans;
    for (int i : h1)
    {
        ans.push_back(i);
    }
    for (int i : h2)
    {
        ans.push_back(i);
    }
    for (int i = ans.size() / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i);
    }
    return ans;
}

int main()
{
    vector<int> h1 = {10, 5, 6, 2};
    vector<int> h2 = {12, 7, 9};
    vector<int> merged = merge_1(h1, h2);
    for (int i : merged)
    {
        cout << i << " ";
    }
    cout << endl;
    merged = merge_2(h1, h2);
    for (int i : merged)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}